using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManagerGO : MonoBehaviour
{
    public Text TotalPlayerXp;
    public Text WON_XP_TEXT;
    public Text player_xp_before;
    private string Pname;
    private int Pxp;
    public int WIN_XP=500;
    public Text DatabaseLogs;
    private void Start()
    {
        Cursor.visible = true;
        WON_XP_TEXT.text = WIN_XP.ToString();
        Cursor.lockState = CursorLockMode.None;
        Pname = VarHolderscript.Instance.Player_Name;
        player_xp_before.text = VarHolderscript.Instance.Player_XP.ToString();
        Pxp = VarHolderscript.Instance.Player_XP+WIN_XP;
        TotalPlayerXp.text = Pxp.ToString();
        StartCoroutine(DBaccess());
    }

    IEnumerator DBaccess()
    {
        WWWForm form = new WWWForm();
        form.AddField("name",Pname);
        form.AddField("xp", Pxp);
        WWW www = new WWW("http://localhost/DataBaseProject/Save_data.php", form);
        yield return www;
        DatabaseLogs.text = www.text;
    }

    public void on_click_quit()
    {
        Application.Quit();
    }

    public void on_click_restart()
    {
        SceneManager.LoadScene(0);
    }
}
