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
    public partial class Admin : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/login.aspx");
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            Copy_to_Music_Folder();
            string file_name = FileUpload1.FileName;
            string base_path = "C:\\\\Users\\\\uzair\\\\Desktop\\\\IPT_project\\\\WebPlayer\\\\Music\\\\"+file_name;
            //debug1.Text = base_path;
            MySqlDataReader reader;
            MySqlCommand cmd;
            string sqlcomm;
            string myConnectionString;
            MySqlConnection conn;
            myConnectionString = "server = LocalHost; user id = root; database = ipt_schema; password = uzair1998";
            conn = new MySqlConnection(myConnectionString);
            conn.Open();

            // For admin
            //INSERT INTO `ipt_schema`.`songs` (`songs_name`, `Song`) VALUES('sjakdh', 'asdnb');
            sqlcomm = "INSERT INTO ipt_schema.songs(songs_name,Song) VALUES('"+file_name+"','"+base_path+"')";
            cmd = new MySqlCommand(sqlcomm, conn);
            reader = cmd.ExecuteReader();
            while (reader.Read()) ;
            { }
            reader.Close();
        }
        protected void Copy_to_Music_Folder()
        {
            if (FileUpload1.HasFile)
             {
               string path = Path.GetFileName(FileUpload1.FileName);
             Label1.Text = FileUpload1.FileName;
             path = path.Replace(" ", "");
             FileUpload1.SaveAs(Server.MapPath("~/Music/") + path);
                warning.Text = "File Uploaded";
                
            }
            else
            {
                warning.Text = "File not uploaded";
            }
        }
    }
}