using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 石头剪刀布
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnStone_Click(object sender, EventArgs e)
        {
            //玩家
            lblPlayer.Text = btnStone.Text;
            Player player = new Player();
            int playerNum = player.PlayerFist(btnStone.Text);

            //电脑
            Computer cpu = new Computer();
            int computerNum = cpu.computerFist();
            lblComputer.Text = cpu.Fist;

            //裁判
            Referee referee = new Referee();
            lblReferee.Text = referee.Result(playerNum, computerNum);
            Method(referee.Result(playerNum, computerNum));
        }


        private void btnScissors_Click(object sender, EventArgs e)
        {
            //玩家
            lblPlayer.Text = btnScissors.Text;
            Player player = new Player();
            int playerNum = player.PlayerFist(btnScissors.Text);

            //电脑
            Computer cpu = new Computer();
            int computerNum = cpu.computerFist();
            lblComputer.Text = cpu.Fist;

            //裁判
            Referee referee = new Referee();
            lblReferee.Text = referee.Result(playerNum, computerNum);
            Method(referee.Result(playerNum, computerNum));
        }

        private void btnCloth_Click(object sender, EventArgs e)
        {
            //玩家
            lblPlayer.Text = btnCloth.Text;
            Player player = new Player();
            int playerNum = player.PlayerFist(btnCloth.Text);

            //电脑
            Computer cpu = new Computer();
            int computerNum = cpu.computerFist();
            lblComputer.Text = cpu.Fist;

            //裁判
            Referee referee = new Referee();
            lblReferee.Text = referee.Result(playerNum, computerNum);
            Method(referee.Result(playerNum, computerNum));
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lblPlayer.Text = null;
            lblComputer.Text = null;
            lblReferee.Text = null;
        }

        public void Method(string str) 
        {
            int i;
            int n;
            if (str == "玩家赢") 
            {
                i = Convert.ToInt32(lblWinPlayer.Text);
                i += 1;
                lblWinPlayer.Text = i.ToString();
            }
            else if (str == "电脑赢")
            {
                n = Convert.ToInt32(lblWinComputer.Text);
                n += 1;
                lblWinComputer.Text = n.ToString();
            }
            else if(str == "平手")
            {
            
            }
        }


    }
}
