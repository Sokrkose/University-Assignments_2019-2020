function curProc = sjf(arrival, flagPreempt)

    persistent runningProcess;
    persistent runningProcessTimeRemaining;
    persistent waitProcesses;
    persistent waitProcessesTime;
    persistent pausedProcesses;
    persistent pausedProcessesTimeRemaining;

    if isempty(runningProcess)
        runningProcess = {};
    end
    if isempty(runningProcessTimeRemaining)
        runningProcessTimeRemaining = [];
    end
    if isempty(waitProcesses)
        waitProcesses = {};
    end
    if isempty(waitProcessesTime)
        waitProcessesTime = [];
    end
    if isempty(pausedProcesses)
        pausedProcesses = {};
    end
    if isempty(pausedProcessesTimeRemaining)
        pausedProcessesTimeRemaining = [];
    end
    
    if isempty(arrival)  
        '';
    else
        waitProcesses{length(waitProcesses)+1} = arrival;
        waitProcessesTime(length(waitProcessesTime)+1) = arrival{2};
    end
      
      
      
    if flagPreempt == false
        if isempty(runningProcess)
            if ~isempty(waitProcesses)
            
                min = waitProcesses{1};
                min = min{2};
                index = 1;
                
                for i = 2:length(waitProcesses)
                    A = waitProcesses{i};
                    A = A{2};
                    if A < min
                        min = A;
                        index = i;
                    end
                end

                runningProcess = waitProcesses{index};
                waitProcesses(index) = [];
                runningProcessTimeRemaining = runningProcess{2} - 1;
                runningProcess{2} = runningProcessTimeRemaining;

                curProc = runningProcess{1};
                return;
                
            else 
            
                curProc = '_';
                return;
                
            end
        else
            if runningProcessTimeRemaining == 0; 
                if ~isempty(waitProcesses)
                
                min = waitProcesses{1}; 
                min = min{2}; 
                index = 1;
                
                for i=2:length(waitProcesses)
                    A = waitProcesses{i}; 
                    A = A{2};
                    if A < min
                        min = A;
                        index = i;
                    end
                end  
                
                runningProcess = waitProcesses{index};
                waitProcesses(index) = [];
                runningProcessTimeRemaining = runningProcess{2} - 1;
                runningProcess{2} = runningProcessTimeRemaining;

                curProc = runningProcess{1};
                return;

                else
                
                    curProc = '_';
                    return;
                    
                end
            else
            
                curProc = runningProcess{1};
                runningProcessTimeRemaining = runningProcessTimeRemaining - 1;
                return;
                
            end  
        end
    end
end