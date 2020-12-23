using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 飞行棋重置
{
    class Program
    {
        static string[] playerName = new string[2];
        static int[] MapNumber = new int[100];
        static int[] playerLocation = new int[2]{0,0};
        static string strA = "";
        static string strB = "";
        static void Main(string[] args)
        {
            bool flag = true;
            bool flag1 = true;
            ShowUI();
            playerNameCheck();
            Console.Clear();
            ShowUI();
            getMapChange();
            Console.WriteLine("{0}的飞机用 Ａ 表示", playerName[0]);
            Console.WriteLine("{0}的飞机用 Ｂ 表示", playerName[1]);
            Map();
            Console.WriteLine();
            Console.WriteLine("请按任意键开始游戏！");
            Console.ReadKey(true);
            Console.Clear();
            ShowUI();
            Map();
            playerUI();

            while (playerLocation[0] < 99 && playerLocation[1] < 99)
            {
                if (flag == true)
                {
                    #region 玩家A摇色子
                    Random r = new Random();
                    Console.WriteLine("请 {0} 按任意键开始摇色子！", playerName[0]);
                    ConsoleKeyInfo rec= Console.ReadKey(true);
                    int ARandom = r.Next(1, 7);

                    if (rec.Key == ConsoleKey.F1) 
                    {
                        ARandom = ReadInt(1, 100);
                    }

                    Console.WriteLine("{0}摇到了{1}！", playerName[0], ARandom);
                    Console.WriteLine("按任意键开始行动…");
                    strA = string.Format("{0}走了{1}步", playerName[0], ARandom);
                    Console.ReadKey(true);
                    playerLocation[0] += ARandom;
                    checkLocation();
                    Console.Clear();
                    ShowUI();
                    Map();
                    playerUI();
                    if (playerLocation[0] == playerLocation[1])
                    {
                        Console.WriteLine("噢，{0}踩到了{1}，{1}退后10步…", playerName[0], playerName[1]);
                        strB = string.Format("{0}给踩到了，{0}退后10步", playerName[1], playerName[1]);
                        Console.WriteLine("按任意键执行！");
                        Console.ReadKey(true);
                        playerLocation[1] -= 10;
                        checkLocation();
                    }
                    else
                    {
                        switch (MapNumber[playerLocation[0]])
                        {
                            case 0:
                                break;
                            case 1:
                                Console.WriteLine("哇，{0}走到了幸运轮盘", playerName[0]);
                                Console.WriteLine("请按任意键开始转轮盘！   1:交换位置  2:轰炸对方  3:前进5格  4:自己退5格  5:自己暂停一回合");
                                Console.ReadKey(true);
                                Random t = new Random();
                                int gameRandom = t.Next(1, 6);
                                if (gameRandom == 1)
                                {
                                    Console.WriteLine("{0}转到了 1 ！  {0}与{1}交换位置！", playerName[0], playerName[1]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strA = string.Format("{0}与{1}交换了位置", playerName[0], playerName[1]);
                                    int temp;
                                    temp = playerLocation[0];
                                    playerLocation[0] = playerLocation[1];
                                    playerLocation[1] = playerLocation[0];
                                    checkLocation();
                                }
                                else if (gameRandom == 2)
                                {
                                    Console.WriteLine("{0}转到了 2 ！ {1}遭到了轰炸！{1}退后10步！", playerName[0], playerName[1]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strA = string.Format("{0}遭到了轰炸！{0}退后10步", playerName[1]);
                                    playerLocation[1] -= 10;
                                    checkLocation();
                                }
                                else if (gameRandom == 3)
                                {
                                    Console.WriteLine("{0}转到了 3 ！ {0}前进5步！", playerName[0]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strA = string.Format("{0}前进5步", playerName[0]);
                                    playerLocation[0] += 5;
                                    checkLocation();
                                }
                                else if (gameRandom == 4)
                                {
                                    Console.WriteLine("{0}转到了 4 ！ {0}退后5格！", playerName[0]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strA = string.Format("{0}退后5步", playerName[0]);
                                    playerLocation[0] -= 5;
                                    checkLocation();
                                }
                                else if (gameRandom == 5)
                                {
                                    Console.WriteLine("{0}转到了 5 ！ {0}暂停一回合！", playerName[0]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strA = string.Format("{0}暂停一回合！", playerName[0]);
                                    flag = false;
                                }
                                break;
                            case 2:
                                Console.WriteLine("噢不！{0}踩到了炸弹！{0}退后7格！", playerName[0]);
                                Console.WriteLine("按任意键执行！");
                                Console.ReadKey(true);
                                strA = string.Format("{0}踩到了炸弹！{0}退后7格", playerName[0]);
                                playerLocation[0] -= 7;
                                checkLocation();
                                break;
                            case 3:
                                Console.WriteLine("红灯！请留步！{0}走到了暂停！", playerName[0]);
                                Console.WriteLine("按任意键执行！");
                                Console.ReadKey(true);
                                strA = string.Format("{0}暂停一回合！！", playerName[0]);
                                flag = false;
                                break;
                            case 4:
                                Console.WriteLine("爽啊！{0}走到了时空隧道！前进十格！", playerName[0]);
                                Console.WriteLine("按任意键执行！");
                                Console.ReadKey(true);
                                strA = string.Format("{0}走到了时空隧道！前进十格！", playerName[0]);
                                playerLocation[0] += 10;
                                checkLocation();
                                break;
                        }
                    }
                    Console.Clear();
                    ShowUI();
                    Map();
                    playerUI();
                    #endregion
                }
                else 
                {
                    flag = true;
                }

                if (flag1 == true)
                {
                    #region 玩家B扔色子
                    Random n = new Random();
                    Console.WriteLine("请 {0} 按任意键开始摇色子！", playerName[1]);
                    ConsoleKeyInfo aa= Console.ReadKey(true);
                    int BRandom = n.Next(1, 7);

                    if (aa.Key == ConsoleKey.F1) 
                    {
                        BRandom = ReadInt(1,100);
                    }
                    Console.WriteLine("{0}摇到了{1}！", playerName[1], BRandom);
                    Console.WriteLine("按任意键开始行动…");
                    strB = string.Format("{0}走了{1}步", playerName[1], BRandom);
                    Console.ReadKey(true);
                    playerLocation[1] += BRandom;
                    checkLocation();
                    Console.Clear();
                    ShowUI();
                    Map();
                    playerUI();
                    if (playerLocation[1] == playerLocation[0])
                    {
                        Console.WriteLine("噢，{0}踩到了{1}，{1}退后10步…", playerName[1], playerName[0]);
                        strA = string.Format("{0}给踩到了，{0}退后10步",playerName[0],playerName[0]);
                        Console.WriteLine("按任意键执行！");
                        Console.ReadKey(true);
                        playerLocation[0] -= 10;
                        checkLocation();
                    }
                    else
                    {
                        switch (MapNumber[playerLocation[0]])
                        {
                            case 0:
                                break;
                            case 1:
                                Console.WriteLine("哇，{0}走到了幸运轮盘", playerName[1]);
                                Console.WriteLine("请按任意键开始转轮盘！   1:交换位置  2:轰炸对方  3:前进5格  4:自己退5格  5:自己暂停一回合");
                                Console.ReadKey(true);
                                Random M = new Random();
                                int gameRandom2= M.Next(1, 6);
                                if (gameRandom2== 1)
                                {
                                    Console.WriteLine("{0}转到了 1 ！  {0}与{1}交换位置！", playerName[1], playerName[0]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strB = string.Format("{0}与{1}交换了位置", playerName[1], playerName[0]);
                                    int temp;
                                    temp = playerLocation[1];
                                    playerLocation[1] = playerLocation[0];
                                    playerLocation[0] = playerLocation[1];
                                    checkLocation();
                                }
                                else if (gameRandom2== 2)
                                {
                                    Console.WriteLine("{0}转到了 2 ！ {1}遭到了轰炸！{1}退后10步！", playerName[1], playerName[0]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strB = string.Format("{0}遭到了轰炸！{0}退后10步", playerName[1]);
                                    playerLocation[0] -= 10;
                                    checkLocation();
                                }
                                else if (gameRandom2== 3)
                                {
                                    Console.WriteLine("{0}转到了 3 ！ {0}前进5步！", playerName[1]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strB = string.Format("{0}前进5步", playerName[1]);
                                    playerLocation[1] += 5;
                                    checkLocation();
                                }
                                else if (gameRandom2== 4)
                                {
                                    Console.WriteLine("{0}转到了 4 ！ {0}退后5格！", playerName[1]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strB = string.Format("{0}退后5步", playerName[1]);
                                    playerLocation[1] -= 5;
                                    checkLocation();
                                }
                                else if (gameRandom2 == 5)
                                {
                                    Console.WriteLine("{0}转到了 5 ！ {0}暂停一回合！", playerName[1]);
                                    Console.WriteLine("按任意键执行！");
                                    Console.ReadKey(true);
                                    strB = string.Format("{0}暂停一回合！", playerName[1]);
                                    flag1 = false;
                                }
                                break;
                            case 2:
                                Console.WriteLine("噢不！{0}踩到了炸弹！{0}退后7格！", playerName[1]);
                                Console.WriteLine("按任意键执行！");
                                Console.ReadKey(true);
                                strB = string.Format("{0}踩到了炸弹！{0}退后7格", playerName[1]);
                                playerLocation[1] -= 7;
                                checkLocation();
                                break;
                            case 3:
                                Console.WriteLine("红灯！请留步！{0}走到了暂停！", playerName[1]);
                                Console.WriteLine("按任意键执行！");
                                Console.ReadKey(true);
                                strB = string.Format("{0}暂停一回合！！", playerName[1]);
                                flag1 = false;
                                break;
                            case 4:
                                Console.WriteLine("爽啊！{0}走到了时空隧道！前进十格！", playerName[1]);
                                Console.WriteLine("按任意键执行！");
                                Console.ReadKey(true);
                                strB = string.Format("{0}走到了时空隧道！前进十格！", playerName[1]);
                                playerLocation[1] += 10;
                                checkLocation();
                                break;
                        }
                    }
                    Console.Clear();
                    ShowUI();
                    Map();
                    playerUI();
                    #endregion
                }
                else 
                {
                    flag1 = true;
                }
            }
            Console.Clear();
            ShowUI();
            Console.WriteLine();
            if (playerLocation[0] >= 99)
            {
                Console.WriteLine("                            恭喜{0}获得了胜利！！！", playerName[0]);
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
        public static int ReadInt(int min, int max)
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

        public static void playerUI() 
        {
            Console.WriteLine("****玩家A B的位置************************玩家A B的信息******");
            Console.Write("      {0} ：{1}                              ", playerName[0], playerLocation[0]);
            Console.WriteLine(strA);
            Console.Write("      {0} ：{1}                              ", playerName[1], playerLocation[1]);
            Console.WriteLine(strB);
            Console.WriteLine();
        }

        //public static void MapGo(int i,int j) 
        //{
        //    if (playerLocation[i] == playerLocation[j])
        //    {
        //        Console.WriteLine("噢，{0}踩到了{1}，{1}退后10步…", playerName[0], playerName[1]);
        //        Console.WriteLine("按任意键执行！");
        //        Console.ReadKey(true);
        //        playerLocation[1] -= 10;
        //        checkLocation();
        //        Console.Clear();
        //        ShowUI();
        //        Map();
        //    }
        //    else 
        //    {
        //        switch (MapNumber[playerLocation[i]]) 
        //        {
        //            case 0:
        //                break;
        //            case 1:
        //                Console.WriteLine();
        //                break;
        //            case 2:
        //                break;
        //            case 3:
        //                break;
        //            case 4:
        //                break;
        //        }
        //    }

        //}
        public static void checkLocation() 
        {
            if (playerLocation[0] >= 99) 
            {
                playerLocation[0] = 99;
            }
            else if (playerLocation[0] < 0) 
            {
                playerLocation[0] = 0;
            }

            if (playerLocation[1] >= 99)
            {
                playerLocation[1] = 99;
            }
            else if (playerLocation[1] < 0)
            {
                playerLocation[1] = 0;
            }
        }
        public static void Map() 
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
                Console.Write(getMapString(i));
            }
            Console.WriteLine();
            for (int i = 30; i < 35; i++) 
            {
                for (int j = 0; j < 29; j++) 
                {
                    Console.Write("  ");
                }
                Console.WriteLine(getMapString(i));
            }
            for (int i = 64; i >= 35; i--) 
            {
                Console.Write(getMapString(i));
            }
            Console.WriteLine();
            for (int i = 65; i < 70; i++) 
            {
                Console.WriteLine(getMapString(i));
            }
            for (int i = 70; i < 100; i++) 
            {
                Console.Write(getMapString(i));
            }
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine();
        }
        public static string getMapString(int i) 
        {
            string result = "";
            if (playerLocation[0] == i && playerLocation[1] == i)
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
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
            else if (playerLocation[0] == i && playerLocation[1] == i)
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
                result = "<>";
            }
            else
            {
                switch (MapNumber[i])
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
        public static void getMapChange() //0表示普通格 1表示幸运轮盘 2表示地雷 3表示暂停 4表示时空隧道
        {
            int[] luckturn = { 6, 23, 40, 55, 69, 83 };
            int[] landmine = {5, 13, 17, 32, 39, 50, 64, 80, 94};
            int[] pase = { 9, 27, 60, 93, 46 };
            int[] time = { 25, 35, 45, 63, 72, 88, 90 };
            for (int i = 0; i < luckturn.Length; i++) 
            {
                MapNumber[luckturn[i]] = 1;
            }
            for (int i = 0; i < landmine.Length; i++) 
            {
                MapNumber[landmine[i]] = 2;
            }
            for (int i = 0; i < pase.Length; i++)
            {
                MapNumber[pase[i]] = 3;
            }
            for (int i = 0; i < time.Length; i++) 
            {
                MapNumber[time[i]] = 4;
            }
        }
        public static void playerNameCheck() 
        {
                Console.WriteLine("请输入玩家A的姓名");
                playerName[0] = Console.ReadLine();
                while (playerName[0] == " " || playerName[0] == "")
                {
                    Console.WriteLine("输入错误，请重新输入");
                    playerName[0] = Console.ReadLine();
                }
                bool flag = true;
                do
                {
                    flag = true;
                    Console.WriteLine("请输入玩家B的姓名");
                    playerName[1] = Console.ReadLine();
                    if (playerName[1] == playerName[0]) 
                    {
                        Console.WriteLine("输入错误，玩家B与玩家A重名，请重新输入");
                        Console.WriteLine();
                        flag = false;
                        continue;
                    }
                    if (playerName[1] == " " || playerName[1] == "") 
                    {
                        Console.WriteLine("输入错误，请重新输入");
                        Console.WriteLine();
                        flag = false;
                        continue;
                    }
                }
                while (flag == false);
            
        }
        public static void ShowUI() 
        {
            Console.WriteLine("**************************************************************************");
            Console.WriteLine("*                                                                        *");
            Console.WriteLine("*                           吴鹏的飞行棋小游戏                           *");
            Console.WriteLine("*                                                                        *");
            Console.WriteLine("**************************************************************************");
        }
    }
}
