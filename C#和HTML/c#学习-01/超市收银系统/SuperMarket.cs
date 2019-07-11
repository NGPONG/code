using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统
{
    public class SuperMarket
    {
        Warehouse cangku = new Warehouse();
        /// <summary>
        /// 通过构造方法存取货物
        /// </summary>
        public SuperMarket()
        {
            cangku.GetCommodity("苹果手机", 100);
            cangku.GetCommodity("Acer电脑", 100);
            cangku.GetCommodity("茶叶蛋", 100);
            cangku.GetCommodity("香蕉照相机", 100);
        }
        public void AskNeed() 
        {
            Show();
            Console.WriteLine("按任意键进入");
            Console.ReadKey(true);
            Console.Clear();
            List<Commodity> ListCom = new List<Commodity>();
            Show();
            cangku.ShowUI();
            Console.WriteLine("请问您需要些什么？\n我们有：苹果手机、Acer电脑、茶叶蛋、香蕉照相机");
            string comName = Console.ReadLine();
            Console.WriteLine("请问您需要多少个");
            int count = int.Parse(Console.ReadLine());
            //去仓库取货物，需要的货物存放在listCom集合中
            cangku.SetCommodity(comName, count,ListCom);
            Console.Clear();
            Show();
            cangku.ShowUI();
            do 
            {
                Console.WriteLine("还需要些什么？\n我们有：苹果手机、Acer电脑、茶叶蛋、香蕉照相机");
                comName = Console.ReadLine();
                if (comName == "不需要") 
                {
                    break;
                }
                Console.WriteLine("请问您需要多少个");
                count = int.Parse(Console.ReadLine());
                cangku.SetCommodity(comName, count,ListCom);
                Console.Clear();
                Show();
                cangku.ShowUI();
            } 
            while (true);
            //计算总价格
            Console.Clear();
            Show();
            cangku.ShowUI();
            double sumMoney = GetAllMoney(ListCom);
            Console.WriteLine("您购买的商品总价格为：{0}", sumMoney);
            //计算打折价格
            Console.WriteLine("我们有以下打折方式：1. 95折 2. 8折 3. 满300减50 4. 满500减100 5. 不打折");
            string choice = Console.ReadLine();
            double realMoney = (GetRealMoney(choice)).GetMoney(sumMoney);
            Console.WriteLine("打完折后，您总计应付：{0}元", realMoney);
            Console.WriteLine("按任意键开始打印小票");
            Console.ReadKey(true);
            Console.Clear();
            //打印小票
            Console.Write("******************************************************************************************");
            Console.WriteLine();
            for (int i = 0; i < ListCom.Count; i++)
            {
                Console.WriteLine("商品名称：{0}\t商品价格：{1}\t商品编码：{2}", ListCom[i].Name,ListCom[i].Price, ListCom[i].Id);
            }
        }

        public void Show() 
        {
            Console.WriteLine("**************************************************************************");
            Console.WriteLine("*                                                                        *");
            Console.WriteLine("*                           欢迎光临吴鹏的小杂货铺                       *");
            Console.WriteLine("*                                                                        *");
            Console.WriteLine("**************************************************************************");
        }
        /// <summary>
        /// 简单工厂模式
        /// </summary>
        /// <param name="choice">用户需求</param>
        /// <returns></returns>
        public MoneyFather GetRealMoney(string choice) 
        {
            MoneyFather mf = null;
            switch (choice) 
            {
                case "1":
                    mf = new SaleMoney(0.95);
                    break;
                case "2":
                    mf = new SaleMoney(0.8);
                    break;
                case "3":
                    mf = new DecreaseMoney(300, 50);
                    break;
                case "4":
                    mf = new DecreaseMoney(500, 100);
                    break;
                case "5":
                    mf = new NomelMoney();
                    break;
            }
            return mf;
        }
        public double GetAllMoney(List<Commodity> listCom) 
        {
            double sum = 0;
            for (int i = 0; i < listCom.Count; i++)
            {
                sum += (listCom[i]).Price;
            }
            return sum;
        }
    }
}
