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

namespace IPT_project
{
    public partial class Form1 : Form
    {
        string myConnectionString;
        MySqlConnection conn;
        
        public Form1()
        {
            InitializeComponent();
            myConnectionString = "server = LocalHost; user id = root; database = ipt_schema; password = uzair1998" ;
             conn = null;   
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                conn = new MySqlConnection(myConnectionString);
                conn.Open();
                Console.WriteLine("database connected");
                var playform = new playerform(conn);
                playform.Show();
            }
            catch (Exception ex)
            {

            }
        }
    }
}
