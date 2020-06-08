using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bullet : MonoBehaviour
{
    public float speed;
    public float explosionSize;
    public float changeSize;
    public GameObject explosionPrefab;
    public Transform explosionPlacement;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position += Vector3.up * speed * Time.deltaTime;
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "enemy")
        {
            Vector3 targetPos = collision.transform.position;
            Destroy(gameObject);

            //creates explosion
            for (int i = 0; i < explosionSize; i++)
            {
                Instantiate(explosionPrefab, targetPos, Quaternion.identity);
            }

            Destroy(collision.gameObject);
        }
        else if (collision.gameObject.tag == "big enemy")
        {
            Destroy(gameObject);
            collision.gameObject.transform.localScale += new Vector3(changeSize, changeSize, changeSize);
        }
    }
}
