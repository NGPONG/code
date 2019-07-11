using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统02
{
     public class Market
    {
         List<Cargo> listCargo = new List<Cargo>();//购物篮子集合
         WareHouse warehouse = new WareHouse();

         /// <summary>
         /// 构造函数为货架装入货物
         /// </summary>
         public Market() 
         {
             warehouse.SetCargo("手提电脑", 25);
             warehouse.SetCargo("可口可乐", 100);
             warehouse.SetCargo("苹果手机", 10);
             warehouse.SetCargo("香蕉", 50);
             warehouse.SetCargo("大话设计模式", 35);
         }

         public void Ask() 
         {
             warehouse.ShowCargo();
             Console.WriteLine("我们有 苹果手机、手提电脑、可口可乐、香蕉、大话设计模式");
             Console.WriteLine("请问您需要什么？");
             string cargoName = Console.ReadLine();
             Console.WriteLine("请问您需要多少件");
             int count = Convert.ToInt32(Console.ReadLine());
             warehouse.GetCargo(cargoName, count, listCargo);
             do 
             {
                 Console.WriteLine("请问您还需要什么？");
                 cargoName = Console.ReadLine();
                 if (cargoName == "不需要") 
                 {
                     break;
                 }
                 Console.WriteLine("请问您需要多少件？");
                 count = Convert.ToInt32(Console.ReadLine());

                 warehouse.GetCargo(cargoName, count, listCargo);
             }
             while (true);

             double allMoney = Money(listCargo);
             Console.WriteLine("总价格为：{0}",allMoney);
             Console.WriteLine("请选择打折模式：1. 95折 2. 8折 3. 满300减50 4. 满500减100 5. 不打折 6. 骨折");
             string choice = Console.ReadLine();
             double realMoney = GetRealMoney(choice).saleMoney(allMoney);
             Console.WriteLine("打完折您应付：{0}元",realMoney);
         }

         public SaleMoney GetRealMoney(string choice) 
         {
             SaleMoney sm = null;
             switch (choice) 
             {
                 case "1":
                     sm = new Discont(0.95);
                     break;
                 case "2":
                     sm = new Discont(0.8);
                     break;
                 case "3":
                     sm = new Decrease(300, 50);
                     break;
                 case "4":
                     sm = new Decrease(500, 100);
                     break;
                 case "5":
                     sm = new Nomal();
                     break;
                 case "6":
                     sm = new Discont(0.1);
                     break;
             }
             return sm;
         }
         public double Money(List<Cargo> listCargo) 
         {
             double sum = 0;
             for (int i = 0; i < listCargo.Count; i++)
             {
                 sum += listCargo[i].Price;
             }
             return sum;
         }
    }
}
