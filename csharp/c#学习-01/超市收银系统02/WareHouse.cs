using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统02
{
    public class WareHouse
    {
        List<List<Cargo>> list = new List<List<Cargo>>();
        public WareHouse() 
        {
            list.Add(new List<Cargo>());//list[0]为computer货架
            list.Add(new List<Cargo>());//list[1]为cola货架
            list.Add(new List<Cargo>());//list[2]为phone货架
            list.Add(new List<Cargo>());//list[3]为banana货架
            list.Add(new List<Cargo>());//list[4]为book货架
        }
        /// <summary>
        /// 把货物装入货架
        /// </summary>
        /// <param name="cargoName"></param>
        /// <param name="count"></param>
        public void SetCargo(string cargoName, int count) 
        {
            for (int i = 0; i < count; i++)
            {
                switch (cargoName) 
                {
                    case "手提电脑":
                        list[0].Add(new Computer("手提电脑", Guid.NewGuid().ToString(), 6688));
                        break;
                    case "可口可乐":
                        list[1].Add(new Cola("可口可乐",Guid.NewGuid().ToString(),3.5));
                        break;
                    case "苹果手机":
                        list[2].Add(new Phone("苹果手机", Guid.NewGuid().ToString(), 8000));
                        break;
                    case "香蕉":
                        list[3].Add(new Banana("香蕉", Guid.NewGuid().ToString(), 4));
                        break;
                    case "大话设计模式":
                        list[4].Add(new Book("大话设计模式", Guid.NewGuid().ToString(), 33.7));
                        break;
                }
            }

        }
        /// <summary>
        /// 把货物从货架取出装入篮子（集合）
        /// </summary>
        /// <param name="cargoName"></param>
        /// <param name="count"></param>
        /// <param name="listCargo"></param>
        public void GetCargo(string cargoName, int count, List<Cargo> listCargo) 
        {
            for (int i = 0; i < count; i++)
            {
                switch (cargoName) 
                {
                    case "手提电脑":
                        listCargo.Add((list[0])[0]);
                        list[0].RemoveAt(0);//从货架上的数组去除一个
                        break;
                    case "可口可乐":
                        listCargo.Add((list[1])[0]);
                        list[1].RemoveAt(0);
                        break;
                    case "苹果手机":
                        listCargo.Add((list[2])[0]);
                        list[2].RemoveAt(0);
                        break;
                    case "香蕉":
                        listCargo.Add((list[3])[0]);
                        list[3].RemoveAt(0);
                        break;
                    case "大话设计模式":
                        listCargo.Add((list[4])[0]);
                        list[4].RemoveAt(0);
                        break;
                }
            }
        }

        public void ShowCargo() 
        {
            foreach (var item in list)
            {
                Console.WriteLine("名称 {0}\t价格：{1}\t数量 {2}",item[0].Name,item[0].Price,item.Count);
            }
        }
    }
}
