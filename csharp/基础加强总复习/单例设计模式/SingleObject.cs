using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 单例设计模式
{
    /// <summary>
    /// 单例类
    /// </summary>
    class SingleObject
    {
        /// <summary>
        /// 私有的构造函数，外部不能访问
        /// 也就是不能创建该类的对象
        /// </summary>
        private SingleObject()
        {
        
        }

        private static SingleObject _single = null;

        public static SingleObject GetSingle() 
        {
            if (_single == null) 
            {
                _single = new SingleObject();
            }
            return _single;
        }

        public Form2 Frm2 { get; set; }

        public Form3 Frm3 { get; set; }

        public Form4 Frm4 { get; set; }

        public Form5 Frm5 { get; set; }

    }
}
