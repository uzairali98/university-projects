using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class VarHolderscript : MonoBehaviour
{
    public static VarHolderscript Instance;

    public int Player_XP;
    public string Player_Name;
    void Awake()
    {
        if (Instance == null)
        {
            DontDestroyOnLoad(gameObject);
            Instance = this;
        }
        else if (Instance != this)
        {
            Destroy(gameObject);
        }
    }
}
