Copyright vivi_and_qiao liwei
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WMPLib;
namespace WindowsFormsApplication1
{

    public partial class Form1 : Form
    {
        int flag = 0;
        int flag1 = 0;
        int flag2 = 0;
        int idx;
        int tem1, tem2;
        string s;
        WMPLib.WindowsMediaPlayer axWindowsMediaPlayer1 = new WindowsMediaPlayer();
        //System.Text.StringBuilder s= new System.Text.StringBuilder();
        String[,] a = new String[9, 4]{
            {"王哲","曹璇璇","张宇飞","赵丹阳"},
            {"周虹","李瑞贤","陈衍烽","刘莹"},
            {"王梦洁","王金龙","王兆鹏","李伟"},
            {"张永健","梁琦","丑朱波","田倩"},
            {"谢东晓","张锦","祝上杰","潘瑞"},
            {"田跃胜","索旭阳","王佳展","曹晨"},
            {"张明","邬慧","王佳展","李阳"},
            {"刘卜蓉","王帅","常青","郜晟堡"},
            {"苟蒸","冯明祥","贾浩","李文顺"},
        };
        String[,] b = new String[9, 4]{
         {"041410","041411","041412","041413"},
         {"041410","041411","041412","041413"},
         {"041410","041411","041412","041413"},
         {"041410","041411","041412","041413"},
         {"041410","041411","041412","041413"},
         {"041410","041411","041412","041413"},
         {"041410","041411","041412","041413"},
         {"041410","041411","041412","041413"},
         {"041419","041411","041412","041413"}
         };
        int help, temp, temp1;
        public Form1()
        {
            InitializeComponent();
            this.label1.BackColor = Color.Transparent;
            this.label2.BackColor = Color.Transparent;
            axWindowsMediaPlayer1.URL = @"E:\chrome下载\下载\441.mp3";
            axWindowsMediaPlayer1.controls.stop();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Random rnd = new Random();
            flag += 1;
            this.Text = "计科1407（卓越）c#随机抽组程序";
            // this.BackColor=Color.FromArgb(255,rnd.Next(255),rnd.Next(255));
            if (flag % 2 == 1)
            {
                this.label1.Text = "  正在抽组";
                this.button1.Text = "单击停止";
                // this.button2.Text = "抽奖";
            }
            else
            {
                this.label1.Text = "  抽组完毕";
                this.button1.Text = "单击开始";

            }
            if (this.label1.Text == "  抽组完毕")
                MessageBox.Show("组内抽人：" + a[temp, rnd.Next(4)]);
            this.pictureBox2.Visible = false;
        }
        private void timer1_Tick(object sender, EventArgs e)
        {

            Random rnd = new Random();

            if (flag % 2 == 1)
            {
                this.timer4.Enabled = false;
                temp = rnd.Next(9);
                temp1 = temp + 1;
                this.BackColor = Color.FromArgb(rnd.Next(255), rnd.Next(255), rnd.Next(255));
                this.label2.Text = "第" + temp1.ToString() + "组：" + a[temp, 0] + "," + a[temp, 1] + "," + a[temp, 2] + "," + a[temp, 3];
                this.label2.ForeColor = Color.FromArgb(rnd.Next(255), rnd.Next(255), rnd.Next(255));
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void label1_Click(object sender, EventArgs e)
        {
            if (flag % 2 == 0 && this.label1.Text != "     抽奖完毕")
                MessageBox.Show("第" + temp1.ToString() + "组详细信息：" + '\n' + a[temp, 0] + " " + b[temp, 0] + '\n' + a[temp, 1] + " " + b[temp, 1] + '\n' + a[temp, 2] + " " + b[temp, 2] + '\n' + a[temp, 3] + " " + b[temp, 3]);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            flag2 += 1;
            if (flag2 % 2 == 1)
            {
                this.button1.Text = "抽组";
                this.label1.Text = "正在抽奖";
                this.button2.Text = "停止";
                this.timer4.Enabled = true;
                this.pictureBox2.Visible = false;
            }
            else
            {
                this.label1.Text = "     抽奖完毕";
                this.button2.Text = "抽奖";
                // this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            }
        }
        private void textBox1_MouseClick_1(object sender, MouseEventArgs e)
        {
            flag1 = 1;
            this.textBox1.Text = "";
            s = "";
        }

        private void textBox1_KeyPress_1(object sender, KeyPressEventArgs e)
        {
            /*
                s.Append(e.KeyChar);
                textBox1.Clear();
                this.textBox1.Multiline = true; 
                this.textBox1.SelectedText=s.ToString();              
                 //MessageBox.Show(s.ToString() + "   " + this.textBox1.Text);
             */


            s = this.textBox1.Text;
            idx = this.textBox1.SelectionStart + 1;
            //  s = s.Insert(idx, "T");
            //s.Append(e.KeyChar);
            this.textBox1.Text = string.Format(s.ToString());
            this.textBox1.SelectionStart = idx + 1;
            this.textBox1.Focus();
            // s = s.Insert(idx, e.KeyChar.ToString());


        }

        private void timer2_Tick_1(object sender, EventArgs e)
        {
            if (flag1 == 0)
                this.textBox1.Text = "    在此处搜索|";
            else
                this.timer2.Enabled = false;

        }

        private void timer3_Tick_1(object sender, EventArgs e)
        {
            if (flag1 == 0)
                this.textBox1.Text = "    在此处搜索";
            else
                this.timer3.Enabled = false;
        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            textBox1.SelectionStart = textBox1.Text.Length;
        }

        private void search_Click(object sender, EventArgs e)
        {
            // MessageBox.Show(s);
            int biaozhi = 0;
            if (!(this.textBox1.Text == "    在此处搜索|" || this.textBox1.Text == "    在此处搜索"))
                for (int i = 0; i < 9; i++)
                    for (int j = 0; j < 4; j++)
                    {
                        if (a[i, j].CompareTo(s.ToString()) == 0 || b[i, j].CompareTo(s.ToString()) == 0)
                        {
                            biaozhi = 1;
                            MessageBox.Show("存在于第" + (i + 1).ToString() + "组" + '\n' + "组内成员如下：" + '\n' + a[i, 0] + "  学号:" + b[i, 0] + '\n' + a[i, 1] + "  学号:" + b[i, 1] + '\n' + a[i, 2] + "  学号:" + b[i, 2] + '\n' + a[i, 3] + "  学号:" + b[i, 3]);
                        }
                    }
            if (biaozhi == 0)
                MessageBox.Show("并未找到你所要的信息，请您重新输入！");
        }

        private void timer4_Tick(object sender, EventArgs e)
        {
            Random rnd = new Random();
            if (flag2 % 2 == 1)
            {

                this.timer4.Enabled = true;
                tem1 = rnd.Next(9); tem2 = rnd.Next(4);
                this.label2.Text = "           " + a[tem1, tem2];

            }
            //tem1 = rnd.Next(9); tem2 = rnd.Next(4);
            if (flag2 % 2 == 0 && flag2 != 0 && flag % 2 == 0)
            {
                //this.timer4.Enabled = false;
                this.label2.Text = "       恭喜" + a[tem1, tem2] + "您中奖了";
                this.pictureBox2.Visible = true;
                this.pictureBox2.BackColor = Color.Transparent;
                axWindowsMediaPlayer1.controls.play();
            }
            if (flag2 == 0)
            {

                this.label2.Text = "      开始后显示名单";
                // this.timer4.Enabled = false;
            }
        }
    }
}
Copyright vivi_and_qiao liwei