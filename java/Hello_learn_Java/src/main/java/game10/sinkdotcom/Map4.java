package game10.sinkdotcom;

public class Map4 {
    private int[][] map = new int[3][3];//1D-2D

    private int count =0;





    public String move(int i, int j,boolean isXTurn){
        String result = "";

        map[i][j] = isXTurn? 1: 2;

        count++;

        result = judge();

        print();

        return result;
    }

    public String judge(){

        if(map[0][0]==1 && map[0][1]==1&& map[0][2]==1 || map[1][0]==1 && map[1][1]==1&& map[1][2]==1
                ||map[2][0]==1 && map[2][1]==1&& map[2][2]==1 || map[0][0]==1 && map[1][1]==1&& map[2][2]==1 ||
                map[0][2]==1 && map[1][1]==1&& map[2][0]==1 )
            return "X_Win";
        else if(map[0][0]==2 && map[0][1]==2 && map[0][2]==2 || map[1][0]==2 && map[1][1]==2 && map[1][2]==2
                ||map[2][0]==2 && map[2][1]==2 && map[2][2]==2 || map[0][0]==2 && map[1][1]==2 && map[2][2]==2 ||
                map[0][2]==2 && map[1][1]==2 && map[2][0]==2 )
            return "O_Win";
        else if(count==9)
            return "Draw";
        else return "Gaming";

    }
    public void print(){
        for(int i =0;i<3;i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(posToString(i, j));
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    public String posToString(int i, int j){
        String symbol = "_";
        if(map[i][j] == 0) symbol = "_";
        else if(map[i][j] == 1) symbol = "X";
        if(map[i][j] == 2) symbol = "O";

        return symbol;

    }
}
