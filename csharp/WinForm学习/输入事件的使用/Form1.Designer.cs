namespace 输入事件的使用
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
            this.components = new System.ComponentModel.Container();
            this.textWrite = new System.Windows.Forms.TextBox();
            this.lblWrite = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // textWrite
            // 
            this.textWrite.Location = new System.Drawing.Point(155, 53);
            this.textWrite.Name = "textWrite";
            this.textWrite.Size = new System.Drawing.Size(100, 21);
            this.textWrite.TabIndex = 0;
            this.textWrite.TextChanged += new System.EventHandler(this.textWrite_TextChanged);
            // 
            // lblWrite
            // 
            this.lblWrite.AutoSize = true;
            this.lblWrite.Location = new System.Drawing.Point(153, 97);
            this.lblWrite.Name = "lblWrite";
            this.lblWrite.Size = new System.Drawing.Size(41, 12);
            this.lblWrite.TabIndex = 1;
            this.lblWrite.Text = "label1";
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(467, 400);
            this.Controls.Add(this.lblWrite);
            this.Controls.Add(this.textWrite);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textWrite;
        private System.Windows.Forms.Label lblWrite;
        private System.Windows.Forms.Timer timer1;
    }
}

