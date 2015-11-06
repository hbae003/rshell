#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

typedef tokenizer<char_separator<char> > mytok;

bool runcmd(vector <char*> cmnd)
{
    //output test 
    //for (unsigned i = 0; i < cmnd.size(); i++)
    //{
    //    cout << cmnd.at(i) << " ";
    //}
    //cout << endl;
    cmnd.push_back('\0');
    int pid = fork();
        if (pid < 0)
        {
            perror ("forking error");
        }
        else if (pid == 0)
        {
            //child
            if (execvp (cmnd[0], &cmnd[0]) < 0)
            {
                perror ("exec");
                return false;
            }
            return true;
        }
        else if (pid > 0) 
        {
            //parent
            if (wait(0) < 0)
            {
                perror ("wait");
                return false;
            }
            return true;
        }
        return false;
}

int main() 
{
    //variables initilaized
    string command; 
    vector <string> parsed;
    vector <char*> cmnd;
    bool previous = true;
    bool comment = false;   
     
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

    cout << user << "@" << host <<  "$ ";
    getline(cin, command);
    
    //create delim for tokenizer
    char_separator<char> delim(" ", ";#");
    tokenizer< char_separator<char> > mytok(command, delim);

    //iterate through the string and save each command in vector
    for (mytok::iterator it = mytok.begin(); it != mytok.end(); ++it)
    { 
        parsed.push_back(*it);
    }

    //separate and run the commands based on connector commands
    for (unsigned i = 0; i < parsed.size(); i++)
    {
        cmnd.push_back(const_cast<char*>(parsed[i].c_str()));
        //branch with different connectors 
        //if comment == true then dont do anything 
        if (comment)
        { }
        else if (strcmp(cmnd.at(cmnd.size() - 1),";") == 0) 
        {
            if (previous == true)
            {
                cmnd.pop_back(); //pop_back so program doesnt execute connector
                runcmd(cmnd);
            }
            cmnd.clear();
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
    runcmd(cmnd);
}

   
    return 0; 
}

