string doesCircleExists(string commands) {

    int len = commands.size();
    int initialDirection[] = {1,0,0,0};

    int direction = 1;
    int l= 0,r = 0,i,x = 0, y=0;
    for(i=0;i<=len;++i) {
        if(commands[i]=='L')
            l++;
        else if(commands[i]=='R')
            r++;
    }
    int n = 100;
    while(n--){
        for(int i=0; i<len; i++){
            if    (direction == 1) {
                if(commands[i]=='L')
                    direction = 4 ;
                else if(commands[i]=='R')
                    direction = 2;
                    else
                    y+=1;
            }
            else if(direction == 2) {
                if(commands[i]=='L')
                    direction = 1;
                else if(commands[i]=='R')
                    direction = 3;
                    else
                    x+=1;
            }
            else if(direction == 3)  {
                if(commands[i]=='L')
                    direction = 2;
                else if(commands[i]=='R')
                    direction = 4;
                    else
                    y-=1;
            }
            else if(direction == 4){
                if(commands[i]=='L')
                    direction = 3;
                else if(commands[i]=='R')
                    direction = 1;
                    else
                    x-=1;
            }
        }
        if(x== 0 && y== 0)
            return "YES";
   }

    if(x==0 && y==0)
        return "YES";
    return "NO";
}

