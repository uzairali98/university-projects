using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
using MySql.Data.MySqlClient;

namespace WebPlayer
{
    public partial class login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            warning.Text = "WELCOME";
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            warning.Text = "WELCOME";
            string email, pass;
            email = TextBox1.Text;
            pass = TextBox2.Text;
         //   debug1.Text = email;
         //   debug2.Text = pass;
            MySqlDataReader reader;
            MySqlCommand cmd;
            string sqlcomm;
            string myConnectionString;
            MySqlConnection conn;
            myConnectionString = "server = LocalHost; user id = root; database = ipt_schema; password = uzair1998";
            conn = new MySqlConnection(myConnectionString);
            conn.Open();

            // For admin
            sqlcomm = "SELECT Email,Password FROM admin";
            cmd = new MySqlCommand(sqlcomm, conn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                if (String.Equals(email,reader.GetString(0)) && String.Equals(pass,reader.GetString(1)))
                {
                    reader.Close();
                    Response.Redirect("~/Admin.aspx");
                    return;
                }
            }
            reader.Close();
            // For user
            sqlcomm = "SELECT Email,Password FROM user";
            cmd = new MySqlCommand(sqlcomm, conn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                if (email == reader.GetString(0) && pass == reader.GetString(1))
                {
                    reader.Close();
                    Response.Redirect("~/WebForm1.aspx");
                    return;
                }
            }
            warning.Text = "Credentials not correct!!!";
            reader.Close();
        }
    }
}