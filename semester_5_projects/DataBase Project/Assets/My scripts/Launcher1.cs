using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Photon.Pun;
using Photon;


public class Launcher1 : MonoBehaviourPunCallbacks
{
    public Text PlayerName;
    public Text RoomName;

    public void Awake()
    {
        PhotonNetwork.AutomaticallySyncScene = true;
        Connect();
    }

    public override void OnConnectedToMaster()
    {
        join();
        base.OnConnectedToMaster();
    }

    public override void OnJoinedRoom()
    {
        startgame();
        base.OnJoinedRoom();
    }

    public override void OnJoinRandomFailed(short returnCode, string message)
    {
        create();
        base.OnJoinRandomFailed(returnCode, message);
    }
public void Connect()
    {
        PhotonNetwork.GameVersion = "0.0.0";
        PhotonNetwork.ConnectUsingSettings();
    }

public void join()
    {
        PhotonNetwork.JoinRandomRoom();

    }
public void create()
    {
        PhotonNetwork.CreateRoom("");
    }
        
    public void startgame()
    {
        if(PhotonNetwork.CurrentRoom.PlayerCount == 1)
        {
            PhotonNetwork.LoadLevel(1);
        }
    }

}
