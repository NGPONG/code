namespace 日期选择器
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.cboYear = new System.Windows.Forms.ComboBox();
            this.cboMonth = new System.Windows.Forms.ComboBox();
            this.cboDay = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // cboYear
            // 
            this.cboYear.FormattingEnabled = true;
            this.cboYear.Location = new System.Drawing.Point(64, 90);
            this.cboYear.Name = "cboYear";
            this.cboYear.Size = new System.Drawing.Size(159, 20);
            this.cboYear.TabIndex = 0;
            this.cboYear.SelectedIndexChanged += new System.EventHandler(this.cboYear_SelectedIndexChanged);
            // 
            // cboMonth
            // 
            this.cboMonth.FormattingEnabled = true;
            this.cboMonth.Location = new System.Drawing.Point(328, 90);
            this.cboMonth.Name = "cboMonth";
            this.cboMonth.Size = new System.Drawing.Size(159, 20);
            this.cboMonth.TabIndex = 1;
            this.cboMonth.SelectedIndexChanged += new System.EventHandler(this.cboMonth_SelectedIndexChanged);
            // 
            // cboDay
            // 
            this.cboDay.FormattingEnabled = true;
            this.cboDay.Location = new System.Drawing.Point(557, 90);
            this.cboDay.Name = "cboDay";
            this.cboDay.Size = new System.Drawing.Size(159, 20);
            this.cboDay.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(869, 579);
            this.Controls.Add(this.cboDay);
            this.Controls.Add(this.cboMonth);
            this.Controls.Add(this.cboYear);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ComboBox cboYear;
        private System.Windows.Forms.ComboBox cboMonth;
        private System.Windows.Forms.ComboBox cboDay;
    }
}

