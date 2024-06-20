package game10.chess;

public class OthelloMap extends Map{

    int count = 0;
    int countX = 0;
    int countO = 0;



    @Override
    public void init() {
        map = new int[8][8];

        map[3][3]=1;
        map[4][4]=1;
        map[3][4]=2;
        map[4][3]=2;

    }

    @Override
    public GameResult judge(int i, int j, boolean isXTurn) {
        System.out.println("i:"+i+" j:"+j+" isXTurn:"+isXTurn);

        count++;

        int[] XNext = {-1,-1,0,1,1,1,0,-1};
        int[] YNext = {0,1,1,1,0,-1,-1,-1};

        if(isXTurn==true) {

            map[i][j] = 1;
        }
        else
            map[i][j] = 2;

        count++;

        Loop2:
        for(int n =0;n<8;n++){

            //get next neighbor
            int r, c;
            r = i+XNext[n];
            c = j+YNext[n];
            int v = 0;
            if(!isOutofBound(r,c)) {
                v = map[r][c];
                //if neighbor not same continue
                if (v == map[i][j]) {
                    continue ;
                } else {

                    do {
                        r = r + XNext[n];
                        c = c + YNext[n];
                        if (!isOutofBound(r, c))
                            v = map[r][c];
                        else
                            continue Loop2;
                    }while(v!= map[i][j]);

                    do {
                        r = r - XNext[n];
                        c = c - YNext[n];
                        if(map[r][c]==1)
                            map[r][c] = 2;
                        else if(map[r][c]==2)
                            map[r][c] = 1;
                    }while((r- XNext[n])!=i||(c- YNext[n])!=j);

                }
            }
            else continue;

        }

        for (int m=0;m<8;m++)
            for (int n=0;n<8;n++){
                if(map[m][n]==1)
                    countX++;
                else countO++;
            }

        if(count==64) {

            if (countX > countO) return GameResult.X_Win;
            else if (countX == countO) return GameResult.DRAW;
            else return GameResult.O_Win;
        }else
            return GameResult.GAMING;
    }



    @Override
    public void print() {

        for (int m=0;m<8;m++) {
            for (int n = 0; n < 8; n++) {
                if (map[m][n] == 1)
                    System.out.print("X ");
                else if (map[m][n] == 2)
                    System.out.print("O ");
                else
                    System.out.print("_ ");

            }
            System.out.println();
        }

    }

    public boolean isOutofBound(int i, int j){
        if(i>=0&&i<8&&j>=0&&j<8)
            return false;
        else
            return true;
    }
}
