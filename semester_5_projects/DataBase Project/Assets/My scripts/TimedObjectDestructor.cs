using UnityEngine;
using System.Collections;
using Photon.Pun;

public class TimedObjectDestructor : MonoBehaviourPunCallbacks
{

	public float timeOut = 1.0f;
	public bool detachChildren = false;

	// Use this for initialization
	void Awake () {
		// invoke the DestroyNow funtion to run after timeOut seconds
		Invoke ("DestroyNow", timeOut);
	}
	
	void DestroyNow ()
	{
		if (detachChildren) { // detach the children before destroying if specified
			transform.DetachChildren ();
		}

		// destory the game Object
		PhotonNetwork.Destroy(gameObject);
	}
}
