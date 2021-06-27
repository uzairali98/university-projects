using UnityEngine;
using System.Collections;
using Photon.Pun;

public class Shooter : MonoBehaviourPunCallbacks
{
	public string ProjectileName;
	public float power = 10.0f;
	private Collider coli;

    private void Start()
    {
		coli = GetComponentInParent<Collider>() ;
    }

    void Update () {

		if (!photonView.IsMine)
			return;
		if(coli.enabled)
		if (Input.GetKeyDown(KeyCode.Mouse0))
		{	
				GameObject newProjectile = PhotonNetwork.Instantiate(ProjectileName, transform.position + transform.forward, transform.rotation) as GameObject;
				newProjectile.GetComponent<Rigidbody>().AddForce(transform.forward * power, ForceMode.VelocityChange);
		}
	}
}
