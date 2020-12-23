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

namespace 用xml文档实现增删查改
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            LoadData();
        }

        private void btnAddOK_Click(object sender, EventArgs e)
        {
            #region 添加数据到XML文件

            string gender = string.Empty;
            if (rdoAddMan.Checked)
            {
                gender = "男";
            }
            else if (rdoAddWoman.Checked)
            {
                gender = "女";
            }
            XmlDocument doc = new XmlDocument();
            doc.Load("haodongxi.xml");

            XmlElement users = doc.DocumentElement;

            XmlElement user = doc.CreateElement("user");
            user.SetAttribute("id", txtAddID.Text);
            users.AppendChild(user);

            XmlElement name = doc.CreateElement("name");
            name.InnerXml = txtAddName.Text;
            user.AppendChild(name);

            XmlElement age = doc.CreateElement("age");
            age.InnerXml = txtAddAge.Text;
            user.AppendChild(age);

            XmlElement xmlgender = doc.CreateElement("gender");
            xmlgender.InnerXml = gender;
            user.AppendChild(xmlgender);

            XmlElement password = doc.CreateElement("password");
            password.InnerXml = txtAddPwd.Text;
            user.AppendChild(password);

            doc.Save("haodongxi.xml");

            #endregion

            //重新加载一次文档
            LoadData();

            MessageBox.Show("注册成功");
        }

        /// <summary>
        /// 加载文档内容
        /// </summary>
        private void LoadData() 
        {
            List<Users> list = new List<Users>();
            XmlDocument doc = new XmlDocument();
            doc.Load("haodongxi.xml");

            XmlNodeList xnl = doc.SelectNodes("Users/user");

            for (int i = 0; i < xnl.Count; i++)
            {
                int id = int.Parse(xnl[i].Attributes["id"].Value);
                string name = xnl[i].SelectSingleNode("name").InnerText;
                int age = int.Parse(xnl[i].SelectSingleNode("age").InnerText);
                char gender = Convert.ToChar(xnl[i].SelectSingleNode("gender").InnerText);
                string password = xnl[i].SelectSingleNode("password").InnerText;

                list.Add(new Users(id, name, age, gender, password));
            }

            //取消显示第一列的空内容
            //dataGridView1.RowHeadersVisible = false;

            //将选项模式改为选中一整行
            dataGridView1.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

            //添加类的集合，该类的属性必须已经赋值
            //一个类就代表一个行
            dataGridView1.DataSource = list;

            //取消选中行
            dataGridView1.ClearSelection();
        }

        /// <summary>
        /// 删除数据
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void 删除ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load("haodongxi.xml");
            XmlElement users = doc.DocumentElement;

            //获得选中行的集合
           DataGridViewSelectedRowCollection dgrc =  dataGridView1.SelectedRows;

           for (int i = 0; i < dgrc.Count; i++)
           {
               //获得选第 i 行元素中下标为0的列的值--ID
               string id = dgrc[i].Cells[0].Value.ToString();

               XmlNode xnDelete = doc.SelectSingleNode(string.Format("Users/user[@id='{0}']", id));
               users.RemoveChild(xnDelete);
           }
           doc.Save("haodongxi.xml");

           LoadData();
           MessageBox.Show("删除成功！");
        }

        
        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            //获取选中行的集合，获取该集合下标为0的列的集合的属性的值
            txtChangeID.Text = dataGridView1.SelectedRows[0].Cells[0].Value.ToString();
            txtChangeName.Text = dataGridView1.SelectedRows[0].Cells[1].Value.ToString();
            txtChangeAge.Text = dataGridView1.SelectedRows[0].Cells[2].Value.ToString();

            if (dataGridView1.SelectedRows[0].Cells[3].Value.ToString() == "男") 
            {
                rdoChangeMan.Checked = true;
            }
            else if (dataGridView1.SelectedRows[0].Cells[3].Value.ToString() == "女") 
            {
                rdoChangeWoman.Checked = true;
            }

            txtChangePwd.Text = dataGridView1.SelectedRows[0].Cells[4].Value.ToString();


            //每次单击的时候 都把当前单击行的Tag赋值ID属性
            //以便记录在修改数据的时候具体要修改哪一行的数据
            dataGridView1.SelectedRows[0].Tag = dataGridView1.SelectedRows[0].Cells[0].Value.ToString();
        }

        /// <summary>
        /// 修改数据
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnChangeOK_Click(object sender, EventArgs e)
        {
            int age = int.Parse(txtChangeAge.Text);
            string name = txtChangeName.Text;
            int id = int.Parse(txtChangeID.Text);
            char gender = '1';
            if (rdoChangeMan.Checked) 
            {
                gender = Convert.ToChar("男");
            }
            else if (rdoChangeWoman.Checked) 
            {
                gender = Convert.ToChar("女");
            }
            string passWord = txtChangePwd.Text;

            Users us = new Users(id, name, age, gender, passWord);

            XmlDocument doc = new XmlDocument();
            doc.Load("haodongxi.xml");

            XmlNode user = doc.SelectSingleNode(string.Format("Users/user[@id='{0}']", dataGridView1.SelectedRows[0].Tag.ToString()));
            user.Attributes["id"].Value = us.ID.ToString();

            XmlNode xmlName = user.SelectSingleNode("name");
            xmlName.InnerXml = us.Name;

            XmlNode xmlAge = user.SelectSingleNode("age");
            xmlAge.InnerXml = us.Age.ToString();

            XmlNode xmlGender = user.SelectSingleNode("gender");
            xmlGender.InnerXml = us.Gender.ToString();

            XmlNode xmlPwd = user.SelectSingleNode("password");
            xmlPwd.InnerXml = us.PassWord;

            doc.Save("haodongxi.xml");
            MessageBox.Show("修改成功！");
            LoadData();

        }
    }
}
