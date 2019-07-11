namespace MDI窗体设计
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
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.纵向排列ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip2 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.纵向排列ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.纵向排列ToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.横向排列ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1.SuspendLayout();
            this.contextMenuStrip2.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.纵向排列ToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(125, 26);
            // 
            // 纵向排列ToolStripMenuItem
            // 
            this.纵向排列ToolStripMenuItem.Name = "纵向排列ToolStripMenuItem";
            this.纵向排列ToolStripMenuItem.Size = new System.Drawing.Size(124, 22);
            this.纵向排列ToolStripMenuItem.Text = "纵向排列";
            // 
            // contextMenuStrip2
            // 
            this.contextMenuStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.纵向排列ToolStripMenuItem1});
            this.contextMenuStrip2.Name = "contextMenuStrip2";
            this.contextMenuStrip2.Size = new System.Drawing.Size(125, 26);
            // 
            // 纵向排列ToolStripMenuItem1
            // 
            this.纵向排列ToolStripMenuItem1.Name = "纵向排列ToolStripMenuItem1";
            this.纵向排列ToolStripMenuItem1.Size = new System.Drawing.Size(124, 22);
            this.纵向排列ToolStripMenuItem1.Text = "纵向排列";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.纵向排列ToolStripMenuItem2,
            this.横向排列ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(596, 25);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 纵向排列ToolStripMenuItem2
            // 
            this.纵向排列ToolStripMenuItem2.Name = "纵向排列ToolStripMenuItem2";
            this.纵向排列ToolStripMenuItem2.Size = new System.Drawing.Size(68, 21);
            this.纵向排列ToolStripMenuItem2.Text = "纵向排列";
            this.纵向排列ToolStripMenuItem2.Click += new System.EventHandler(this.纵向排列ToolStripMenuItem2_Click);
            // 
            // 横向排列ToolStripMenuItem
            // 
            this.横向排列ToolStripMenuItem.Name = "横向排列ToolStripMenuItem";
            this.横向排列ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.横向排列ToolStripMenuItem.Text = "横向排列";
            this.横向排列ToolStripMenuItem.Click += new System.EventHandler(this.横向排列ToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(596, 493);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.contextMenuStrip1.ResumeLayout(false);
            this.contextMenuStrip2.ResumeLayout(false);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 纵向排列ToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip2;
        private System.Windows.Forms.ToolStripMenuItem 纵向排列ToolStripMenuItem1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 纵向排列ToolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem 横向排列ToolStripMenuItem;
    }
}

