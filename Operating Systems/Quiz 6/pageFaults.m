function status = pageFaults(pageReq, nFrame)

    persistent frames = zeros(nFrame, 1);
    persistent timesMeasured = zeros(nFrame, 1);
    
    flag = 0;
    for i = 1:nFrame           
        if (frames(i) == pageReq)
            flag = 1;
            timesMeasured(i) = time;
            break;
        end
    end
    
    if(flag == 1)
        status = 'H';
        return;
    else
        status = 'M';
    end
        
    [M,I] = min(timesMeasured);
    timesMeasured(I) = time;
    timesMeasured(I) = pageReq;
        
end