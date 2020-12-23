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
            //创建玩家对象
            Player play = new Player(btnStone.Text);
            lblPlayer.Text = btnStone.Text;

            //创建电脑对象
            Computer cpu = new Computer();
            lblComputer.Text = cpu.CpuLbl();

            //创建裁判对象
            Referee re = new Referee(play.PlayerFirst, cpu.ComputerFirst);

            //执行裁判结果
            lblReferee.Text = re.GerResult();
        }

        private void btnScissors_Click(object sender, EventArgs e)
        {
            //创建玩家对象
            Player play = new Player(btnScissors.Text);
            lblPlayer.Text = btnScissors.Text;

            //创建电脑对象
            Computer cpu = new Computer();
            lblComputer.Text = cpu.CpuLbl();

            //创建裁判对象
            Referee re = new Referee(play.PlayerFirst, cpu.ComputerFirst);

            //执行裁判结果
            lblReferee.Text = re.GerResult();
        }

        private void btnCloth_Click(object sender, EventArgs e)
        {
            //创建玩家对象
            Player play = new Player(btnCloth.Text);
            lblPlayer.Text = btnCloth.Text;

            //创建电脑对象
            Computer cpu = new Computer();
            lblComputer.Text = cpu.CpuLbl();

            //创建裁判对象
            Referee re = new Referee(play.PlayerFirst, cpu.ComputerFirst);

            //执行裁判结果
            lblReferee.Text = re.GerResult();
        }
    }
}
