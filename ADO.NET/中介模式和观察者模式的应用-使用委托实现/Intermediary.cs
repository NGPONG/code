using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 中介模式和观察者模式的应用_使用委托实现
{
    public partial class Intermediary : Form
    {
        public Intermediary()
        {
            InitializeComponent();
        }

        private void btnShowFrm_Click(object sender, EventArgs e)
        {
            Subject sub = new Subject();
            ObserverFrm1 frm1 = new ObserverFrm1();
            ObserverFrm2 frm2 = new ObserverFrm2();

            sub.del += frm1.GetMsgFrm1;
            sub.del += frm2.GetMsgFrm2;

            sub.Show();
            frm1.Show();
            frm2.Show();
        }
    }
}
