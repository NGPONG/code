using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统
{
    public class Warehouse
    {
        List<List<Commodity>> list = new List<List<Commodity>>();//生成一个大仓库集合，能够存放货物的货架
       
        /// <summary>
       ///通过构造方法生成货架list[i] 
       /// </summary>
        public Warehouse() 
        {
            list.Add(new List<Commodity>()); //list[0]为存放Iphone的货架
            list.Add(new List<Commodity>()); //list[1]为存放Acer的货架
            list.Add(new List<Commodity>()); //list[2]为存放茶叶蛋的货架
            list.Add(new List<Commodity>()); //list[3]为存放香蕉照相机的货架
        }

        /// <summary>
        /// 为货架list[i]存放商品的对象
        /// </summary>
        /// <param name="comName">存放商品名称</param>
        /// <param name="count">存放商品数量</param>
        public void GetCommodity(string comName,int count) //*
        {
            for (int i = 0; i < count; i++)
            {
                switch (comName) 
                {
                    case "苹果手机":
                        list[0].Add(new Iphone(5000,"苹果手机" ,Guid.NewGuid().ToString()));
                        break; 
                    case "Acer电脑":
                        list[1].Add(new Acer(5000, "宏基电脑", Guid.NewGuid().ToString()));
                        break;
                    case "茶叶蛋":
                        list[2].Add(new TeaEggs(200,"茶叶蛋",Guid.NewGuid().ToString()));
                        break;
                    case "香蕉照相机":
                        list[3].Add(new BananaCamera(2000,"香蕉照相机",Guid.NewGuid().ToString()));
                            break;
                }
            }
        }
        /// <summary>
        /// 从list[i]货架上取出货物
        /// </summary>
        /// <param name="comName">取出商品名称</param>
        /// <param name="count">取出商品数量</param>
        public void SetCommodity(string comName, int count,List<Commodity> listCom)
        {
            for (int i = 0; i < count; i++)
            {
                switch (comName)
                {
                    case "苹果手机":
                        listCom.Add((list[0])[0]);
                        list[0].RemoveAt(0);
                        break;
                    case "Acer电脑":
                        listCom.Add((list[1])[0]);
                        list[1].RemoveAt(0);
                        break;
                    case "茶叶蛋":
                        listCom.Add((list[2])[0]);
                        list[2].RemoveAt(0);
                        break;
                    case "香蕉照相机":
                        listCom.Add((list[3])[0]);
                        list[3].RemoveAt(0);
                        break;
                }
            }
        }
        /// <summary>
        /// 展示货物
        /// </summary>
        public void ShowUI() //*
        {
            for (int i = 0; i < list.Count; i++)
            {
                Console.WriteLine("商品名称：{0}\t商品价格：{1}\t商品数量：{2}",(list[i])[i].Name,(list[i])[i].Price,list[i].Count);
            }
            Console.WriteLine();
        }
    }
}
