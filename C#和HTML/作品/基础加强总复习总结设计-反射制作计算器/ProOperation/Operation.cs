using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProOperation
{
    public abstract class Operation
    {
        public int NumberOne { get; set; }
        public int NumberTwo { get; set; }
        public Operation(int numberone, int numbertwo) 
        {
            this.NumberOne = numberone;
            this.NumberTwo = numbertwo;
        }

        /// <summary>
        /// 记录子类的运算符，只读属性
        /// </summary>
        public abstract string Type 
        { 
            get;
        }
        /// <summary>
        /// 运算方法
        /// </summary>
        /// <returns></returns>
        public abstract int GetResult();
    }
}
