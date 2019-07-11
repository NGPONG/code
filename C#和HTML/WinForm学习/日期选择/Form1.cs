using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 日期选择
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cboYear.Items.Add("请选择年份");
            cboMonth.Items.Add("请选择月份");
            cboDay.Items.Add("请选择日子");
            for (int i = 2017; i >=1800; i--)
            {
                cboYear.Items.Add(i + "年");
            }
            cboYear.SelectedIndex = 0;
            cboMonth.SelectedIndex = 0;
            cboDay.SelectedIndex = 0;
        }

        private void cboYear_SelectedIndexChanged(object sender, EventArgs e)
        {
            cboMonth.Items.Clear();
            cboMonth.Items.Add("请选择月份");
            cboMonth.SelectedIndex = 0;
            if (cboYear.SelectedIndex != 0) 
            {
                for (int i = 1; i < 13; i++)
                {
                    cboMonth.Items.Add(i + "月");
                }
            }
        }

        private void cboMonth_SelectedIndexChanged(object sender, EventArgs e)
        {
                string[] strArraryYear = cboYear.SelectedItem.ToString().Split(new char[] { '年' }, StringSplitOptions.RemoveEmptyEntries);
                string[] strArraryMonth = cboMonth.SelectedItem.ToString().Split(new char[] { '月' }, StringSplitOptions.RemoveEmptyEntries);
                string strA = strArraryYear[0];
                string strB = strArraryMonth[0];
                int year = Convert.ToInt32(strA);
                int month = Convert.ToInt32(strB);

                if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year == 2) 
                {
                    for (int i = 1; i <= 29; i++)
                    {
                        cboDay.Items.Add(i + "日");
                    }
                }
        }

    }
}
