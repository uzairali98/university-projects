using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class camera_pan : MonoBehaviour
{

    public Camera cam;
    
    void Update()
    {
        this.cam.transform.Rotate(0f, 0.2f, 0f, Space.World);
    }
}