using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
using WMPLib;

namespace IPT_project
{
    public partial class playerform : Form
    {
        MySqlConnection conn;
        MySqlDataReader reader;
        MySqlCommand cmd;
        string sql;
        string music_path;
        WMPLib.WindowsMediaPlayer wplayer;
        public playerform(MySqlConnection connection)
        {
            InitializeComponent();
            conn = connection;
            sql = "SELECT songs_name FROM songs";
            cmd = new MySqlCommand(sql, conn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                songlist_textbox.AppendText(reader.GetString(0) + Environment.NewLine);
            }
            
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            reader.Close();
            string song_name = song_name_textbox.Text;
            Console.WriteLine(song_name);
            sql = "SELECT Song FROM songs WHERE songs_name = '" + song_name+"'";
            cmd = new MySqlCommand(sql, conn);
            reader = cmd.ExecuteReader();
            reader.Read();
            music_path = reader.GetString(0);
            wplayer = new WMPLib.WindowsMediaPlayer();
            wplayer.URL = music_path;
            wplayer.controls.play();
            volume_label.Text = Convert.ToString(wplayer.settings.volume);
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            wplayer.controls.pause();
        }

        private void Stop_button_Click(object sender, EventArgs e)
        {
            wplayer.controls.stop();
        }

        private void Resume_song_button_Click(object sender, EventArgs e)
        {
            wplayer.controls.play();
            
        }

        private void Volume_down_button_Click(object sender, EventArgs e)
        {
            if (wplayer.settings.volume >= 10)
            {
                wplayer.settings.volume -= 10;
                volume_label.Text = Convert.ToString(wplayer.settings.volume);
            }
        }

        private void Volume_up_button_Click(object sender, EventArgs e)
        {
            if (wplayer.settings.volume < 100)
            {
                wplayer.settings.volume += 10;
                volume_label.Text = Convert.ToString(wplayer.settings.volume);
            }
        }

        private void Playerform_Load(object sender, EventArgs e)
        {

        }
    }
}
