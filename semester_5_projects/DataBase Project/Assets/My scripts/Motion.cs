using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class Motion : MonoBehaviourPunCallbacks
{
    public float speed;
    public GameObject parentcamera;
    public Camera playercam;
    public float sprintFOV = 1.25f;
    
    private Rigidbody rig;
    private float baseFOV;
    void Start()
    {
        parentcamera.SetActive(photonView.IsMine);
        baseFOV = playercam.fieldOfView;
        rig = GetComponent<Rigidbody>();
    }

    private void FixedUpdate()
    {
        if (!photonView.IsMine)
            return; 
        float t_hmove = Input.GetAxis("Horizontal");
        float t_vmove = Input.GetAxis("Vertical");

        Vector3 t_direction = new Vector3(t_hmove, 0, t_vmove);
        t_direction.Normalize();

        if (Input.GetKey(KeyCode.LeftShift) == true && t_vmove > 0)
        {
            playercam.fieldOfView =Mathf.Lerp(playercam.fieldOfView,baseFOV * sprintFOV, Time.deltaTime * 8f);
            float temp = speed * 5;
            rig.velocity = transform.TransformDirection(t_direction) * temp * Time.deltaTime;
        }
        else
        {
            playercam.fieldOfView = Mathf.Lerp(playercam.fieldOfView, baseFOV , Time.deltaTime * 8f);
            rig.velocity = transform.TransformDirection(t_direction) * speed * Time.deltaTime;
        }
    }
    
}
