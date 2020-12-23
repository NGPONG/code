using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 抽象工厂.Pro;
using 抽象工厂.ProRoot;
using 抽象工厂.FactoryAbstract;

namespace 抽象工厂.Factory
{
    public class FemalFactory : IAnimalFactory
    {
        public Animal CreateCat()
        {
            return new FemaleCat();
        }

        public Animal CreateDog()
        {
            return new FemaleDog();
        }
    }
}
