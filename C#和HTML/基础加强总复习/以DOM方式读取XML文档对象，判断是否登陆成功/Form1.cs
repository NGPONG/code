using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace 以DOM方式读取XML文档对象_判断是否登陆成功
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        List<Person> list = new List<Person>();
        private void Form1_Load(object sender, EventArgs e)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load("person.xml");

            XmlNodeList xnl = doc.SelectNodes("Person/Student");

            for (int i = 0; i < xnl.Count; i++)
            {
                string name = xnl[i].SelectSingleNode("Name").InnerText;
                string age = xnl[i].SelectSingleNode("Age").InnerText;
                string gender = xnl[i].SelectSingleNode("Gender").InnerText;
                string id = xnl[i].Attributes["studentID"].Value;

                list.Add(new Person(name,id,gender,age));
            }
        }

        private void btnEnter_Click(object sender, EventArgs e)
        {
            string gender = string.Empty;
            if (rdoMan.Checked) 
            {
                gender = "男";
            }
            else if (rdoWoman.Checked) 
            {
                gender = "女";
            }

            bool flag = false;
            for (int i = 0; i < list.Count; i++)
            {
                if ((txtName.Text == list[i].Name) && (txtID.Text == list[i].ID) && (txtAge.Text == list[i].Age )&& (gender == list[i].Gender))
                {
                    MessageBox.Show("登陆成功");
                    flag = true;
                    break;
                }
            }

            if (flag == false) 
            {
                MessageBox.Show("登录失败");
            }
        }
    }
}
