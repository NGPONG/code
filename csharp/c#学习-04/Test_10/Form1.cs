using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_10
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dataGridView1.AutoGenerateColumns = false;

            var dt = new DataTable();
            dt.Columns.Add("Id");
            dt.Columns.Add("Value1");
            dt.Columns.Add("Value2");

            dt.Rows.Add(1, "aa", "xx");
            dt.Rows.Add(2, "bb", "yy");
            dt.Rows.Add(3, "cc", "zz");

            this.dataGridView1.DataSource = dt;
            this.dataGridView1.CellPainting += this.DataGridView1_CellPainting;
        }

        private void DataGridView1_CellPainting(object sender, DataGridViewCellPaintingEventArgs e)
        {
            //e.AdvancedBorderStyle.Top = DataGridViewAdvancedCellBorderStyle.None;
        }
    }
}
