using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using Photon;

public class destroy : MonoBehaviourPunCallbacks
{
    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag == "Player")
        {
            PhotonNetwork.Destroy(gameObject);
        }
    }
}
