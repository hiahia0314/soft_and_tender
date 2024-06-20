package game10.sinkdotcom;

public class Map3 {
    private int[][] map = new int[7][7];//1D-2D

    public Map3(){
        map[0][0] = 1; //A0
        map[0][1] = 1; //A1
        map[0][2] = 1; //A2
        map[2][0] = 2; //C0
        map[3][0] = 2; //D0
        map[4][0] = 2; //E0
        map[4][4] = 3; //E4
        map[4][5] = 3; //E5
        map[4][6] = 3; //E6
    }


    public int getPositionI(int i,int j){
        return map[i][j];

    }
    public boolean contains(int n){
        boolean hasIt = false;
        for(int i=0;i<map.length;i++){
            for(int j =0;j<map[0].length;j++)
                if(map[i][j]==n) {
                    hasIt = true;
                    break;
                }
        }
        return hasIt;
    }

    public void clearPostionI(int i,int j){
        map[i][j]=map[i][j]*(-1);
    }

    public String judge(int i, int j){
        String result = "";

        int status =getPositionI(i,j);
        if(status>0){
            clearPostionI(i,j);
            if(contains(status))
                result="hit";
            else {
                result="kill";
            }
        }else{
            result="miss";
        }

        return result;
    }
}
