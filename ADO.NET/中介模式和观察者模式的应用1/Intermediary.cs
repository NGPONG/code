using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 中介模式和观察者模式的应用1
{
    public partial class Intermediary : Form
    {
        public Intermediary()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //创建被观察者窗体的对象
            Subject sub = new Subject();
            //创建观察者窗体的对象
            ObserverFrm1 obFrm1 = new ObserverFrm1();
            ObserverFrm2 obFrm2 = new ObserverFrm2();
            ObserverFrm3 obFrm3 = new ObserverFrm3();

            //观察者订阅被观察者的消息源
            sub.GetMessageList.AddRange(new IGetMessageAble[] { obFrm1, obFrm2, obFrm3 });

            obFrm1.Show();
            obFrm2.Show();
            obFrm3.Show();
            sub.Show();
        }
    }
}
