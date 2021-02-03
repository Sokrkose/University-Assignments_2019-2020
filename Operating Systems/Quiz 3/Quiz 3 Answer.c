int execvpWithTimeout( int timeout, char **cmd ){

    int pid1, pid2, status1, status2;
    pid1 = fork();
    
    if(pid1 == 0){
            sleep(timeout);
            exit(2);
    }else{

        pid2 = fork();
        
        if(pid2 == 0){
            execvp(*cmd,cmd);
            perror(*cmd);
            exit(1);
        }
        int return_pid = wait(&status1);
        kill(pid2, SIGKILL);
        kill(pid1, SIGKILL);
        wait(&status2);

        if(return_pid == pid2 && WEXITSTATUS(status1) != 0) 
            return 1;
        return WEXITSTATUS(status1);
    }

}
