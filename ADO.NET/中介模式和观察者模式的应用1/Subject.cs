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
    public partial class Subject : Form
    {
        public List<IGetMessageAble> GetMessageList { get; set; }
        public Subject()
        {
            InitializeComponent();
            this.GetMessageList = new List<IGetMessageAble>();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < GetMessageList.Count; i++)
            {
                GetMessageList[i].GetMessage(this.textBox1.Text);
            }
          
        }
    }
}
