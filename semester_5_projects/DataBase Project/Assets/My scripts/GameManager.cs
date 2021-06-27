using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using Photon.Pun;
using System;

public class GameManager : MonoBehaviourPunCallbacks
{
    public string PlayerPrefabName;
    public Transform SpawnPoint0;
    public Transform SpawnPoint1;
    public Transform SpawnPoint2;
    public Transform SpawnPoint3;
    public Text PlayerScoreTxt;
    public Text PlayerHealthTxt;
    public static GameManager gm;
    private int randval;

    private void Start()
    {
        gm = gameObject.GetComponent<GameManager>();
        spawn();
    }

    private void Update()
    {
        if(PhotonNetwork.CurrentRoom.PlayerCount==1)
        {
            PhotonNetwork.Disconnect();
            SceneManager.LoadScene(3);
        }
    }

    public void spawn()
    {
        UnityEngine.Random.InitState((int)System.DateTime.Now.Ticks);
        randval = Mathf.RoundToInt(UnityEngine.Random.Range(0, 3));
        switch (randval)
        {

            case (0):
                PhotonNetwork.Instantiate(PlayerPrefabName, SpawnPoint0.position, SpawnPoint0.rotation);
                break;

            case (1):
                PhotonNetwork.Instantiate(PlayerPrefabName, SpawnPoint1.position, SpawnPoint1.rotation);
                break;

            case (2):
                PhotonNetwork.Instantiate(PlayerPrefabName, SpawnPoint2.position, SpawnPoint2.rotation);
                break;

            case (3):
                PhotonNetwork.Instantiate(PlayerPrefabName, SpawnPoint3 .position, SpawnPoint3.rotation);
                break;

        }  
    } 

    public void displayscore(int val)
    {
        PlayerScoreTxt.text = val.ToString();
    }

    public void displayhealth (int val)
    {
        PlayerHealthTxt.text = val.ToString();
    }
}
