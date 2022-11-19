using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float m_speed = 1;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        float movev = 0;
        float moveh = 0;
        if (Input.GetKey(KeyCode.W)) {
            movev += m_speed * Time.deltaTime;
        }
        else if (Input.GetKey(KeyCode.S)) {
            movev -= m_speed * Time.deltaTime;
        }
        else if (Input.GetKey(KeyCode.A))
        {
            moveh -= m_speed * Time.deltaTime;
        }
        else if (Input.GetKey(KeyCode.D))
        {
            moveh += m_speed * Time.deltaTime;
        }
        this.transform.Translate(new Vector3(moveh,movev));
    }
}
