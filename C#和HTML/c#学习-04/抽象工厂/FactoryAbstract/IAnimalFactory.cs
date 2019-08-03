using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 抽象工厂.ProRoot;

namespace 抽象工厂.FactoryAbstract
{
    interface IAnimalFactory
    {
        Animal CreateDog();
        Animal CreateCat();
    }
}
