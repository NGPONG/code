using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 抽象工厂.FactoryAbstract;
using 抽象工厂.Pro;
using 抽象工厂.ProRoot;

namespace 抽象工厂.Factory
{
    public class MaleFactory : IAnimalFactory
    {
        public Animal CreateCat()
        {
            return new MaleCat();
        }

        public Animal CreateDog()
        {
            return new MaleDog();
        }
    }
}
