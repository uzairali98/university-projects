using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using Photon.Pun;
using System;
public class Damage : MonoBehaviourPunCallbacks
{
    public int MaxHealth;
    public int DamageValue;
    private int CurrentHealth;
    private int playerscore = 0;
    private int randval;
    private Renderer rend;
    private Collider collider;
    private PhotonView PV;
    private void Start()
    {
        PV = GetComponent<PhotonView>();
        rend = GetComponent<Renderer>();
        collider = GetComponent<Collider>();
         CurrentHealth = MaxHealth;
    }

    private void Update()
    {
        if (!photonView.IsMine)
            return;
        if(CurrentHealth>=0)
        GameManager.gm.displayhealth(CurrentHealth);
        if (CurrentHealth == 0)
        {
            CurrentHealth--;
            rend.enabled = false;
            collider.enabled = false;
            Invoke("REspawn", 5);
        }
    }
    void OnCollisionEnter(Collision shot)
    {
        if (!photonView.IsMine)
            return;
        if (shot.gameObject.tag == "Projectile")
        {
            CurrentHealth -= DamageValue;
        }
    }

    [PunRPC]
    void updatescore()
    {
        playerscore++;
        Debug.Log("player score is " + playerscore);
        GameManager.gm.displayscore(playerscore);
        if (playerscore == 2)
        {
            Debug.Log("player won" + playerscore);
            PhotonNetwork.Disconnect();
            SceneManager.LoadScene(2);
        }
    }

    void REspawn()
    {
        if (!photonView.IsMine)
            return;
        UnityEngine.Random.InitState((int)System.DateTime.Now.Ticks);
        randval = Mathf.RoundToInt(UnityEngine.Random.Range(0, 3));
        switch (randval)
        {
            case (0):
                PV.transform.position  = GameManager.gm.SpawnPoint0.position;
                break;

            case (1):
                PV.transform.position = GameManager.gm.SpawnPoint1.position;
                break;

            case (2):
                PV.transform.position = GameManager.gm.SpawnPoint2.position;
                break;

            case (3):
                PV.transform.position = GameManager.gm.SpawnPoint3.position;
                break;
        }
        photonView.RPC("updatescore", RpcTarget.Others);
        CurrentHealth = MaxHealth;
        collider.enabled = true;
        rend.enabled = true;
    }
}
