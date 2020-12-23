using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 抽象工厂.Factory;
using 抽象工厂.FactoryAbstract;
using 抽象工厂.ProRoot;

namespace 抽象工厂
{
    class Program
    {
        static void Main(string[] args)
        {
            // 创建生成某种产品类型的工厂
            IAnimalFactory animalFactory = new MaleFactory();

            // 根据上一步所创建的工厂生产相应类型产品族的产品
            Animal cat = animalFactory.CreateCat();
            Animal dog = animalFactory.CreateDog();

            cat.Gender();
            dog.Gender();

            Console.ReadLine();

            
        }
    }
}
