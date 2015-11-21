#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

typedef tokenizer<char_separator<char> > mytok;

bool runcmd(vector <char*> cmnd)
{
    /*
    //output test 
    for (unsigned i = 0; i < cmnd.size(); i++)
    {
       cout << cmnd.at(i) << " ";
    }
    cout << endl; */
    
    cmnd.push_back('\0');
    int pid = fork();
    int status;
    if (pid < 0)
    {
        perror ("forking error");
        return false;
    }
    else if (pid == 0)
    {
        //child
        if(execvp(cmnd[0], &cmnd[0]) < 0)
        {
            perror ("exec");
            exit(1);
        }
        return true;
    }
    else if (pid > 0) 
    {
        //parent
        if(waitpid(pid, &status, 0) == -1)
        {
            perror("Wait Error");
            return false;
        }
        if(status == 0)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool runTest(vector <char*> cmnd)
{
    cmnd.pop_back();
    const char* pathname = cmnd.at(cmnd.size() - 1);
    const char* flag = cmnd.at(cmnd.size() - 2);
    struct stat sb;
    int a = stat(pathname, &sb);
    
    if (strcmp(flag, "-f") == 0)
    { 
        if (S_ISREG(sb.st_mode)) 
        {
             return true;
        }
        return false;
    }
    else if (strcmp(flag, "-d") == 0)
    {
        if (S_ISDIR(sb.st_mode))
        {
            return true;
        }
        return true;
    }  
    else if (strcmp(flag, "-e") == 0)
    {
        if (a == 0)
        {
            return true; 
        }
        return false;
    }
    else 
    {
        cout << "error: flag doesnt exist" << endl;
        cout << flag << endl;
        return false;
    }
   
}

int main() 
{
    //variables initilaized
    string command; 
    vector <string> parsed;
    vector <char*> cmnd;
    bool previous = true;  //checks if prev command ran 
    bool comment = false;  //checks if the rest are commented
    bool prevOr = false;  //checks if previous command was an or
    bool parError = false;  //checks if there is a parenthesis error
    bool falseParen = false; //if previous = false before the parenthesis, this = true
    bool stringing = false;  //if vector.at(i) is " then this becomes true
    bool isTest = false; 
    bool tested = false;
    int numOfLeftPar = 0;
    int numOfRightPar = 0;
 
    char host[200];//allocate memeory for host
    char* user;
    int hStat = gethostname(host, 200);
    if(hStat !=0){
        perror("Cannot get Host Name");
    }
    if(getlogin() != NULL){
        user = getlogin();
    }else{
        perror("Cannot get User Name");
    }
    
    while (true){
    cmnd.clear();
    parsed.clear();
    comment = false;
    previous = true;
    prevOr = false;
    parError = false;
    falseParen = false;
    stringing = false;
    isTest = false;
    numOfLeftPar = 0;
    numOfRightPar = 0;

    cout << user << "@" << host <<  "$ ";
    getline(cin, command);

    /*
    //test 
    const char* pathname = "/home/csmajs/hbae003/cs100/hw1/src";
    struct stat sb;
    cout << stat(pathname, &sb) << endl;
    if (S_ISREG(sb.st_mode)) 
    {
        cout << "ITS A REGULARFILE" << endl;
    }
    else if (S_ISDIR(sb.st_mode))
    {
        cout << "ITS A DIRECTORY" << endl;
    } 
    */

    //create delim for tokenizer
    char_separator<char> delim(" ", ";#()\"");
    tokenizer< char_separator<char> > mytok(command, delim);

    //iterare through the string and count the number of parenthesis 
    for (mytok::iterator it = mytok.begin(); it != mytok.end(); ++it)
    {
       if (*it == "(")
       { 
           numOfLeftPar++;
       }
       if (*it == ")")
       {
           numOfRightPar++;
       }
    }

    // manually output error 
    if (numOfLeftPar == numOfRightPar)
    {
        //do nothing;
    }
    else if (numOfLeftPar > numOfRightPar)
    {
        cout << "syntax error near unexpected token \'(\'" << endl;
        parError = true;
    }
    else 
    {
        cout << "syntax error near unexpected token \')\'" << endl;
        parError = true;
    }

    //iterate through the string and save each command in vector
    for (mytok::iterator it = mytok.begin(); it != mytok.end(); ++it)
    { 
        parsed.push_back(*it);
    }
    
    /*
    //example output
    for (unsigned i = 0; i < parsed.size(); i++)
    {
        cout << parsed.at(i) << endl; 
    }
    */

    //separate and run the commands based on connector commands
    for (unsigned i = 0; i < parsed.size(); i++)
    {
        cmnd.push_back(const_cast<char*>(parsed[i].c_str()));
        //tested is false for every iteration
        tested = false;
        //check if isTest is true
        const char* temp = cmnd.at(cmnd.size() - 1);
        //is isTest is true and the end last string is a connector
        if (isTest == true && 
           (strcmp(temp, "&&") == 0 || strcmp(temp, "||") == 0 
           || strcmp(temp, ";") == 0)) 
        {
            if(previous == true)
            {
                if (strcmp(temp, "||") == 0)
                {
                    previous = !runTest(cmnd);
                    prevOr = true;
                }
                else
                {
                    previous = runTest(cmnd);
                }
            }
            else
            {
                //do nothing
            }

            if(prevOr)
            {
                prevOr = false;
                previous = true; 
            }           
            isTest = false;
            cmnd.clear();
            tested = true; 
        }

        //branch with different connectors 
        //if comment == true then dont do anything 
        if (comment)
        { }
        //if there is parError, leave loop
        else if (tested)
        {
            //do nothing
        }
        else if (parError)
        {
            i = parsed.size(); 
            previous = false;
        }
        else if (strcmp(cmnd.at(cmnd.size() - 1), "(") == 0)
        {
            if (previous)
            {
                //delete from cmnd and do nothing
                cmnd.pop_back(); 
            }
            else if (!previous)
            {
                //make falseParen true
                falseParen = true;
            }
        }
        else if (strcmp(cmnd.at(cmnd.size() - 1), ")") == 0)
        {
            if (falseParen == false)
            {
                //delete from cmnd and do nothing
                cmnd.pop_back();
            }
            else if (falseParen == true)
            {
                falseParen = false;
                //clear cmnd 
                cmnd.clear();
            }
        }
        else if (falseParen)
        {
            //do nothing
        }
        //from here check for test command
        else if (strcmp(cmnd.at(cmnd.size() - 1), "test") == 0 || 
                 strcmp(cmnd.at(cmnd.size() - 1), "[") == 0)
        {
            isTest = true;
        }
        else if (strcmp(cmnd.at(cmnd.size() - 1), "]") == 0)
        {
            //delete it and do nothing
            cmnd.pop_back();
        }
        else if (strcmp(cmnd.at(cmnd.size() - 1), "exit") == 0 && cmnd.size() == 1)
        { 
            if(previous == true)
            {
                exit(0);
            }
        }
        else if (strcmp(cmnd.at(cmnd.size() - 1),";") == 0) 
        {
            if (previous == true)
            {
                cmnd.pop_back(); //pop_back so program doesnt execute connector
                runcmd(cmnd);
            }
            cmnd.clear();
            previous = true;
        }
        //if && then exec command if previous is true 
        //if previous was false, then dont exec and set previous to false
        else if (strcmp(cmnd.at(cmnd.size() - 1), "&&") == 0)
        {
            if (previous == true)
            {
                cmnd.pop_back();
                previous = runcmd(cmnd);
            }
            else
            {
                previous = false;
            }
            cmnd.clear();
            //if prev connector was || then its true no matter what
            if(prevOr)
            {
                prevOr = false;
                previous = true; 
            }

        }
        //if previous was true then run the program
        /*if previous was false, then dont exec. If current command doesn't exec,
         *then the next command should exec so make previous true*/
        else if (strcmp(cmnd.at(cmnd.size() - 1), "||") == 0)
        {
            if (previous == true)
            {
                cmnd.pop_back();
                previous = !runcmd(cmnd);
            }
            else
            {
                previous = true;
            }
            cmnd.clear();
            if(prevOr)
            {
                prevOr = false;
                previous = false; 
            }
            //the previous was or connector
            else
            {
                prevOr = true; 
            }
        } 
        //run the commands that came before and set comment to true
        else if (strcmp(cmnd.at(cmnd.size() - 1), "#") == 0)
        {
            comment = true;
            cmnd.pop_back();
            runcmd(cmnd);
        }
        //do nothing if its a comment or not a connector command
        else
        {};       

    }
//if there were no connector commands or hash we still need to execute cmnd
if (cmnd.size() > 0 && !comment && previous)
{
    if (!isTest)
    {
        runcmd(cmnd);
    }
    else
    {
        cmnd.push_back('\0');
        runTest(cmnd);
    }
}

}//end of while   

    return 0; 
}

