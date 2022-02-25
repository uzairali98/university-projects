namespace IPT_project
{
    partial class playerform
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.songlist_textbox = new System.Windows.Forms.TextBox();
            this.song_name_textbox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.pause_button = new System.Windows.Forms.Button();
            this.stop_button = new System.Windows.Forms.Button();
            this.resume_song_button = new System.Windows.Forms.Button();
            this.volume_up_button = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.volume_down_button = new System.Windows.Forms.Button();
            this.volume_label = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // songlist_textbox
            // 
            this.songlist_textbox.Location = new System.Drawing.Point(30, 33);
            this.songlist_textbox.Multiline = true;
            this.songlist_textbox.Name = "songlist_textbox";
            this.songlist_textbox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.songlist_textbox.Size = new System.Drawing.Size(734, 221);
            this.songlist_textbox.TabIndex = 0;
            // 
            // song_name_textbox
            // 
            this.song_name_textbox.Location = new System.Drawing.Point(181, 290);
            this.song_name_textbox.Name = "song_name_textbox";
            this.song_name_textbox.Size = new System.Drawing.Size(334, 26);
            this.song_name_textbox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(26, 296);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(149, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Enter Name To Play";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(566, 279);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(116, 48);
            this.button1.TabIndex = 3;
            this.button1.Text = "Play Song";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button1_Click);
            // 
            // pause_button
            // 
            this.pause_button.Location = new System.Drawing.Point(181, 417);
            this.pause_button.Name = "pause_button";
            this.pause_button.Size = new System.Drawing.Size(116, 48);
            this.pause_button.TabIndex = 4;
            this.pause_button.Text = "Pause Song";
            this.pause_button.UseVisualStyleBackColor = true;
            this.pause_button.Click += new System.EventHandler(this.Button2_Click);
            // 
            // stop_button
            // 
            this.stop_button.Location = new System.Drawing.Point(474, 417);
            this.stop_button.Name = "stop_button";
            this.stop_button.Size = new System.Drawing.Size(116, 48);
            this.stop_button.TabIndex = 5;
            this.stop_button.Text = "Stop Song";
            this.stop_button.UseVisualStyleBackColor = true;
            this.stop_button.Click += new System.EventHandler(this.Stop_button_Click);
            // 
            // resume_song_button
            // 
            this.resume_song_button.Location = new System.Drawing.Point(318, 417);
            this.resume_song_button.Name = "resume_song_button";
            this.resume_song_button.Size = new System.Drawing.Size(137, 48);
            this.resume_song_button.TabIndex = 6;
            this.resume_song_button.Text = "Resume Song";
            this.resume_song_button.UseVisualStyleBackColor = true;
            this.resume_song_button.Click += new System.EventHandler(this.Resume_song_button_Click);
            // 
            // volume_up_button
            // 
            this.volume_up_button.Location = new System.Drawing.Point(423, 505);
            this.volume_up_button.Name = "volume_up_button";
            this.volume_up_button.Size = new System.Drawing.Size(30, 34);
            this.volume_up_button.TabIndex = 7;
            this.volume_up_button.Text = "+";
            this.volume_up_button.UseVisualStyleBackColor = true;
            this.volume_up_button.Click += new System.EventHandler(this.Volume_up_button_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(354, 512);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(63, 20);
            this.label2.TabIndex = 8;
            this.label2.Text = "Volume";
            // 
            // volume_down_button
            // 
            this.volume_down_button.Location = new System.Drawing.Point(318, 505);
            this.volume_down_button.Name = "volume_down_button";
            this.volume_down_button.Size = new System.Drawing.Size(30, 34);
            this.volume_down_button.TabIndex = 9;
            this.volume_down_button.Text = "-";
            this.volume_down_button.UseVisualStyleBackColor = true;
            this.volume_down_button.Click += new System.EventHandler(this.Volume_down_button_Click);
            // 
            // volume_label
            // 
            this.volume_label.AutoSize = true;
            this.volume_label.Location = new System.Drawing.Point(367, 555);
            this.volume_label.Name = "volume_label";
            this.volume_label.Size = new System.Drawing.Size(0, 20);
            this.volume_label.TabIndex = 10;
            // 
            // playerform
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(782, 659);
            this.Controls.Add(this.volume_label);
            this.Controls.Add(this.volume_down_button);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.volume_up_button);
            this.Controls.Add(this.resume_song_button);
            this.Controls.Add(this.stop_button);
            this.Controls.Add(this.pause_button);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.song_name_textbox);
            this.Controls.Add(this.songlist_textbox);
            this.Name = "playerform";
            this.Text = "playerform";
            this.Load += new System.EventHandler(this.Playerform_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox songlist_textbox;
        private System.Windows.Forms.TextBox song_name_textbox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button pause_button;
        private System.Windows.Forms.Button stop_button;
        private System.Windows.Forms.Button resume_song_button;
        private System.Windows.Forms.Button volume_up_button;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button volume_down_button;
        private System.Windows.Forms.Label volume_label;
    }
}