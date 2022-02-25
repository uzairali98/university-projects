﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
using MySql.Data.MySqlClient;

namespace WebPlayer
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }


         protected void Button1_Click(object sender, EventArgs e)
        {
            //Label3.Text = ListBox1.Text;
            string path=ListBox1.Text;
            string link = "Music/"+path;

            link = "<audio Controls><Source src=" + link + " type=audio/mpeg></video>";
            Literal1.Text = link;


        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/login.aspx");
        }
    }
}