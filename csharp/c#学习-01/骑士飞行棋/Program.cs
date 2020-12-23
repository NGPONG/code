using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 骑士飞行棋
{
    class Program
    {
        //在下面的数组存储我们游戏地图各各关卡
        //数组的下标为0的元素对应地图上的第1格   下标为1的元素对应第2格...下标为n的元素对应n+1格
        //在数组中用  1:表标幸运轮盘◎
        //            2:地雷☆
        //            3:暂停▲
        //            4:时空隧道卐
        //            0:表示普通
        static int[] map = new int[100];
        static int[] playerLocation = { 0, 0 }; ///表示玩家的位置
        static string[] playerName = new string[2];//表示玩家的名字
        static bool[] Stop = { true, true };
        static void Main(string[] args)
        {
            Program.ShowUI();//调用游戏界面的方法
            playerName = playerNameMethod(playerName);//输入玩家姓名 包括出错的解决方案的方法
            //接收playNameMethod方法中的返回值
            Console.Clear();
            Program.ShowUI();
            ShoyUI2();
            Program.Initialmap();
            Program.DrawMap();

            while (playerLocation[0] < 99 && playerLocation[1] < 99)
            {
                if (Stop[0] == true)
                {
                    #region  玩家A 掷骰子
                    Console.WriteLine("请{0}按下任意键开始掷骰子……", playerName[0]);
                    Console.ReadKey(true);
                    Random r = new Random();//用于获取随机数
                    int aDic = r.Next(1, 7); //aDic为产生的随机数
                    Console.WriteLine("{0}扔出了{1}！", playerName[0], aDic);
                    Console.WriteLine("按任意键开始行动！");
                    Console.ReadKey(true);
                    playerLocation[0] += 3;
                    Console.Clear();
                    ShowUI();
                    ShoyUI2();
                    checkLocation();
                    DrawMap();

                    if (playerLocation[0] == playerLocation[1]) //判断A是否踩到B
                    {
                        Console.WriteLine("{0}踩到了{1}", playerName[0], playerName[1]);
                        Console.WriteLine("{0}后退10步，按任意键继续！", playerName[1]);
                        playerLocation[1] -= 10;
                        checkLocation();
                        Console.ReadKey(true);
                        Console.Clear();
                        ShowUI();
                        ShoyUI2();
                        checkLocation();
                        DrawMap();
                    }
                    else
                    {
                        switch (map[playerLocation[0]])
                        {
                            case 0: //表示走到白格的情况
                                break;
                            case 1://表示走到幸运轮盘的情况
                                Console.WriteLine("恭喜{0}走到了幸运轮盘！请选择运气  1：交换位置  2：轰炸对方 \a", playerName[0]);
                                int userInt = ReadInt(1, 2);
                                if (userInt == 1)
                                {
                                    int temp;//让A和B交换位置
                                    temp = playerLocation[0];
                                    playerLocation[0] = playerLocation[1];
                                    playerLocation[1] = temp;
                                    Console.WriteLine("{0}与{1}交换了位置！", playerName[0], playerName[1]);
                                    Console.WriteLine("按任意键继续！");
                                    Console.ReadKey(true);
                                    Console.Clear();
                                    ShowUI();
                                    ShoyUI2();
                                    checkLocation();
                                    DrawMap();
                                }
                                else
                                {
                                    Console.WriteLine("{0}选择了轰炸{1}！{2}后退10步！", playerName[0], playerName[1], playerName[1]);
                                    playerLocation[1] -= 4;//让B -4步
                                    checkLocation();
                                    Console.WriteLine("按任意键继续！");
                                    Console.ReadKey(true);
                                    Console.Clear();
                                    ShowUI();
                                    ShoyUI2();
                                    checkLocation();
                                    DrawMap();
                                }
                                break;
                            case 2://表示走到地雷的情况
                                Console.WriteLine("噢不！{0}踩到了地雷！ \a", playerName[0]);
                                Console.WriteLine("{0}后退5格", playerName[0]);
                                playerLocation[0] = playerLocation[0] - 6;
                                checkLocation();
                                Console.WriteLine("按任意键继续！");
                                Console.ReadKey(true);
                                Console.Clear();
                                ShowUI();
                                ShoyUI2();
                                DrawMap();
                                break;
                            case 3://表示走到暂停的情况
                                Console.WriteLine("{0}走到了暂停!", playerName[0]);
                                Console.WriteLine("{0}下回合不允许掷骰子！",playerName[0]);
                                Console.WriteLine("按任意键继续！");
                                Stop[0] = false;
                                Console.ReadKey(true);
                                Console.Clear();
                                ShowUI();
                                ShoyUI2();
                                checkLocation();
                                DrawMap();
                                break;
                            case 4://表示走到时空隧道的情况
                                Console.WriteLine("哇，{0}走进了时空隧道！ \a", playerName[0]);
                                playerLocation[0] += 10;
                                checkLocation();
                                Console.WriteLine("按任意键继续！");
                                Console.ReadKey(true);
                                Console.Clear();
                                ShowUI();
                                ShoyUI2();
                                checkLocation();
                                DrawMap();
                                break;
                        }
                    }


                    #endregion
                }
                else 
                {
                    Stop[0] = true;
                }

                if (playerLocation[0] >= 99) 
                {
                    break;
                }

                if (Stop[1] == true)
                {
                    #region 玩家B 掷骰子
                    Console.WriteLine("请{0}按下任意键开始掷骰子……", playerName[1]);
                    Console.ReadKey(true);
                    Random t = new Random();//用于获取随机数
                    int bDic = t.Next(1, 7); //aDic为产生的随机数
                    Console.WriteLine("{0}扔出了{1}！", playerName[1], bDic);
                    Console.WriteLine("按任意键开始行动！");
                    Console.ReadKey(true);
                    playerLocation[1] += bDic;
                    Console.Clear();
                    ShowUI();
                    ShoyUI2();
                    checkLocation();
                    DrawMap();

                    if (playerLocation[1] == playerLocation[0]) //判断B是否踩到A
                    {
                        Console.WriteLine("{0}踩到了{1}", playerName[1], playerName[0]);
                        Console.WriteLine("{0}后退10步，按任意键继续！", playerName[0]);
                        playerLocation[0] -= 10;
                        checkLocation();
                        Console.ReadKey(true);
                        Console.Clear();
                        ShowUI();
                        ShoyUI2();
                        checkLocation();
                        DrawMap();
                    }
                    else
                    {
                        switch (map[playerLocation[1]])
                        {
                            case 0: //表示走到白格的情况
                                break;
                            case 1://表示走到幸运轮盘的情况
                                Console.WriteLine("恭喜{0}走到了幸运轮盘！请选择运气  1：交换位置  2：轰炸对方 \a", playerName[1]);
                                int userInt = ReadInt(1, 2);
                                if (userInt == 1)
                                {
                                    int temp;//让A和B交换位置
                                    temp = playerLocation[1];
                                    playerLocation[1] = playerLocation[0];
                                    playerLocation[0] = temp;
                                    Console.WriteLine("{0}与{1}交换了位置！", playerName[1], playerName[0]);
                                    Console.WriteLine("按任意键继续！");
                                    Console.ReadKey(true);
                                    Console.Clear();
                                    ShowUI();
                                    ShoyUI2();
                                    checkLocation();
                                    DrawMap();
                                }
                                else
                                {
                                    Console.WriteLine("{0}选择了轰炸{1}！{2}后退10步！", playerName[1], playerName[0], playerName[0]);
                                    playerLocation[0] -= 10;//让B -4步
                                    checkLocation();
                                    Console.WriteLine("按任意键继续！");
                                    Console.ReadKey(true);
                                    Console.Clear();
                                    ShowUI();
                                    ShoyUI2();
                                    checkLocation();
                                    DrawMap();
                                }
                                break;
                            case 2://表示走到地雷的情况
                                Console.WriteLine("噢不！{0}踩到了地雷！ \a", playerName[1]);
                                Console.WriteLine("{0}后退5格", playerName[1]);
                                playerLocation[1] = playerLocation[1] - 5;
                                checkLocation();
                                Console.WriteLine("按任意键继续！");
                                Console.ReadKey(true);
                                Console.Clear();
                                ShowUI();
                                ShoyUI2();
                                DrawMap();
                                break;
                            case 3://表示走到暂停的情况
                                Console.WriteLine("{0}走到了暂停", playerName[1]);
                                Console.WriteLine("{0}下回合不允许掷骰子！",playerName[1]);
                                Console.WriteLine("按任意键继续！");
                                Stop[0] = false;
                                Console.ReadKey(true);
                                Console.Clear();
                                ShowUI();
                                ShoyUI2();
                                checkLocation();
                                DrawMap();
                                break;
                            case 4://表示走到时空隧道的情况
                                Console.WriteLine("哇，{0}走进了时空隧道！ \a", playerName[1]);
                                playerLocation[1] += 10;
                                checkLocation();
                                Console.WriteLine("按任意键继续！");
                                Console.ReadKey(true);
                                Console.Clear();
                                ShowUI();
                                ShoyUI2();
                                checkLocation();
                                DrawMap();
                                break;
                        }
                    }
                    #endregion
                }
                else 
                {
                    Stop[1] = true;
                }

                if (playerLocation[1] >= 99) 
                {
                    break;
                }

            }
            Console.Clear();
            ShowUI();
            Console.WriteLine();
            if (playerLocation[0] >= 99) 
            {
                Console.WriteLine("                            恭喜{0}获得了胜利！！！",playerName[0]);
                Console.WriteLine("                            恭喜{0}获得了胜利！！！", playerName[0]);
                Console.WriteLine("                            恭喜{0}获得了胜利！！！", playerName[0]);
                Console.WriteLine("                            重要的事情说三遍");
            }
            if (playerLocation[1] >= 99)
            {
                Console.WriteLine("                            恭喜{0}获得了胜利！！！", playerName[1]);
                Console.WriteLine("                            恭喜{0}获得了胜利！！！", playerName[1]);
                Console.WriteLine("                            恭喜{0}获得了胜利！！！", playerName[1]);
                Console.WriteLine("                            重要的事情说三遍");
            }
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine("                          游戏结束！ 按任意键退出");
            Console.ReadKey(true);


        }

        public static void MapGo(int i,int j) 
        {

            if (playerLocation[i] == playerLocation[j]) //判断A是否踩到B
            {
                Console.WriteLine("{0}踩到了{1}", playerName[i], playerName[j]);
                Console.WriteLine("{0}后退10步，按任意键继续！", playerName[j]);
                playerLocation[j] -= 10;
                checkLocation();
                Console.ReadKey(true);
                Console.Clear();
                ShowUI();
                ShoyUI2();
                checkLocation();
                DrawMap();
            }
            else
            {
                switch (map[playerLocation[i]])
                {
                    case 0: //表示走到白格的情况
                        break;
                    case 1://表示走到幸运轮盘的情况
                        Console.WriteLine("恭喜{0}走到了幸运轮盘！请选择运气  1：交换位置  2：轰炸对方 \a", playerName[i]);
                        int userInt = ReadInt(1, 2); //让输入的数字只能在1 和 2 的方法
                        if (userInt == 1)
                        {
                            int temp;//让A和B交换位置
                            temp = playerLocation[i];
                            playerLocation[i] = playerLocation[j];
                            playerLocation[j] = temp;
                            Console.WriteLine("{0}与{1}交换了位置！", playerName[i], playerName[j]);
                            Console.WriteLine("按任意键继续！");
                            Console.ReadKey(true);
                            Console.Clear();
                            ShowUI();
                            ShoyUI2();
                            checkLocation();
                            DrawMap();
                        }
                        else
                        {
                            Console.WriteLine("{0}选择了轰炸{1}！{2}后退10步！", playerName[i], playerName[j], playerName[j]);
                            playerLocation[j] -= 10;//让B -10步
                            checkLocation();
                            Console.WriteLine("按任意键继续！");
                            Console.ReadKey(true);
                            Console.Clear();
                            ShowUI();
                            ShoyUI2();
                            checkLocation();
                            DrawMap();
                        }
                        break;
                    case 2://表示走到地雷的情况
                        Console.WriteLine("噢不！{0}踩到了地雷！ \a", playerName[i]);
                        Console.WriteLine("{0}后退5格", playerName[i]);
                        playerLocation[i] = playerLocation[i] - 5;
                        checkLocation();
                        Console.WriteLine("按任意键继续！");
                        Console.ReadKey(true);
                        Console.Clear();
                        ShowUI();
                        ShoyUI2();
                        DrawMap();
                        break;
                    case 3://表示走到暂停的情况
                        break;
                    case 4://表示走到时空隧道的情况
                        Console.WriteLine("哇，{0}走进了时空隧道！ \a", playerName[i]);
                        playerLocation[i] += 10;
                        checkLocation();
                        Console.WriteLine("按任意键继续！");
                        Console.ReadKey(true);
                        Console.Clear();
                        ShowUI();
                        ShoyUI2();
                        checkLocation();
                        DrawMap();
                        break;
                }
            }
        }
        public static int ReadInt(int min, int max)  //让用户走到幸运轮盘只能输入1 和2 的方法
        {
            while (true)
            {
                try
                {
                    int number = int.Parse(Console.ReadLine());
                    if (number < min || number > max)
                    {
                        Console.WriteLine("输入错误，只能输入{0}和{1}", min, max);
                        continue;
                    }
                    return number;
                }
                catch
                {
                    Console.WriteLine("输入有误，只能输入{0}和{1}", min, max);
                }
            }
        }
        public static void checkLocation() //检测A B是否越界的方法
        {
            for (int i = 0; i < 2; i++)
            {
                if (playerLocation[i] > 99)
                {
                    playerLocation[i] = 99;
                }
                if (playerLocation[i] < 0)
                {
                    playerLocation[i] = 0;
                }
            }
        }
        public static string GetMapString(int i) //为地图上的坐标赋上特殊符号 或者是前进的方法0
        {
            string result = "";                          //int pos 表示走的第几格，当走的第pos格的时候 再判断需要输出什么符号
            if (playerLocation[0] == i && playerLocation[1] == i)// i = 5  (0,6)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                result = "<>";
            }
            else if (playerLocation[0] == i)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                result = "Ａ";
            }
            else if (playerLocation[1] == i)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                result = "Ｂ";
            }
            else
            {
                switch (map[i])
                {
                    case 0:
                        Console.ForegroundColor = ConsoleColor.White;
                        result = "□";
                        break;
                    case 1:
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        result = "◎";
                        break;
                    case 2:
                        Console.ForegroundColor = ConsoleColor.Red;
                        result = "▲";
                        break;
                    case 3:
                        Console.ForegroundColor = ConsoleColor.Yellow;
                        result = "◆";
                        break;
                    case 4:
                        Console.ForegroundColor = ConsoleColor.Green;
                        result = "★";
                        break;
                }
            }
            return result;
        }
        public static void DrawMap() //绘制地图的方法 
        {
            Console.Write("图例：");
            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.Write("幸运轮盘 ◎    ");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write("地雷 ▲    ");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("暂停 ◆    ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("时空隧道 ★");
            for (int i = 0; i < 30; i++)
            {
                //if (i == 29)
                //{
                //    Console.ForegroundColor = ConsoleColor.White;
                //    Console.Write("□         玩家{0}的位置为：{1}",playerName[0],playerLocation[0]+1);
                //}
                //else
                //{
                Console.Write(Program.GetMapString(i));
                //}
            }
            Console.WriteLine();

            for (int i = 30; i < 35; i++)
            {
                for (int j = 0; j < 29; j++)
                {
                    Console.Write("  ");
                }
                //if (i == 31)
                //{
                //    Console.ForegroundColor = ConsoleColor.White;
                //    Console.Write("□         玩家{0}的位置为：{1}", playerName[1], playerLocation[1] + 1);
                //    Console.WriteLine();
                //}
                //else
                //{
                Console.WriteLine(Program.GetMapString(i));
                //}
            }
            for (int i = 64; i >= 35; i--)
            {
                Console.Write(Program.GetMapString(i));
            }
            Console.WriteLine();
            for (int i = 65; i < 70; i++)
            {
                Console.WriteLine(Program.GetMapString(i));
            }
            for (int i = 70; i < 100; i++)
            {
                Console.Write(Program.GetMapString(i));
            }
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.White;


        }
        public static void Initialmap() //为表示地图位置的数组赋初值的方法
        {
            int[] luckyTurn = { 6, 23, 40, 55, 69, 83 };                        ///这个代表幸运轮盘，里面的数据代表map数组中的下标 
            int[] landMine = { 5, 13, 17, 32, 39, 50, 64, 80, 94 };      ///地雷
            int[] pause = { 9, 27, 60, 93, 46 };                                  ///暂停
            int[] timeTunnel = { 25, 35, 45, 63, 72, 88, 90 };           ///时空隧道

            for (int i = 0; i < luckyTurn.Length; i++)   //把luckyTurn数组中的数据取出，赋值给一个int类型变量，该变量就代表这map数组中的下标
            {
                map[luckyTurn[i]] = 1;
            }

            for (int i = 0; i < landMine.Length; i++) //把landMine数组中的数据取出，赋值给一个int类型变量，该变量就代表这map数组中的下标
            {
                map[landMine[i]] = 2;
            }

            for (int i = 0; i < pause.Length; i++) //把pause数组中的数据取出，赋值给一个int类型变量，该变量就代表这map数组中的下标
            {
                map[pause[i]] = 3;
            }

            for (int i = 0; i < timeTunnel.Length; i++)//把timeTunnel数组中的数据取出，赋值给一个int类型变量，该变量就代表这map数组中的下标
            {
                map[timeTunnel[i]] = 4;
            }
        }
        public static void ShowUI() //调用游戏界面的方法
        {
            Console.WriteLine("**************************************************************************");
            Console.WriteLine("*                                                                        *");
            Console.WriteLine("*                           吴鹏的飞行棋小游戏                           *");
            Console.WriteLine("*                                                                        *");
            Console.WriteLine("**************************************************************************");
            Console.WriteLine();
        }
        public static string[] playerNameMethod(string[] playerName) //输入玩家姓名 包括出错的解决方案的方法
        {
            Console.WriteLine("                            请输入玩家\"1\"的姓名");
            Console.Write("                                   ");
            playerName[0] = Console.ReadLine();
            while (playerName[0] == " " || playerName[0] == "")
            {
                Console.WriteLine("                            输入错误，输入姓名不能为空");
                playerName[0] = Console.ReadLine();
            }
            bool flag = true;
            do
            {
                Console.WriteLine("                            请输入玩家\"2\"的姓名");
                Console.Write("                                   ");
                playerName[1] = Console.ReadLine();
                flag = true;
                if (playerName[1] == playerName[0])
                {
                    Console.WriteLine("                            输入有误，玩家\"1\"和玩家\"2\"重名，请重新输入");
                    Console.WriteLine();
                    flag = false;
                    continue;
                }
                if (playerName[1] == " " || playerName[1] == "")
                {
                    Console.WriteLine("                            输入错误，输入姓名不能为空");
                    Console.WriteLine();
                    flag = false;
                    continue;
                }
            }
            while (flag == false);
            return playerName;
        }
        public static void ShoyUI2()
        {
            Console.WriteLine("对战开始………");
            Console.WriteLine("{0}的飞机用 Ａ 表示   {1}的飞机用 Ｂ 表示", playerName[0], playerName[1]);
            //Console.WriteLine("{0}的飞机用 Ｂ 表示", playerName[1]);
            Console.WriteLine("如果玩家\"A\"和玩家\"B\"在同一位置，用<>来表示");
            Console.WriteLine("玩家{0}的位置为：{1}", playerName[0], playerLocation[0] + 1);
            Console.WriteLine("玩家{0}的位置为：{1}", playerName[1], playerLocation[1] + 1);
        }


    }
}