using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    public float movementSpeed;
    public float movementAfterCollision;
    public Rigidbody rb;
    public bool collided;
    public GameObject sphereSpawn;


    // Start is called before the first frame update
    void Start()
    {
        collided = false;
    }

    // Update is called once per frame
    void Update()
    {

    }

    private void FixedUpdate()
    {
        if (!collided)
        {
            
            rb.AddTorque(Vector3.forward * -movementSpeed);
            rb.velocity = Vector3.right * movementSpeed;
        }

    }

    private void OnCollisionEnter(Collision collision)
    {
        collided = true;
        Debug.Log(gameObject.name + " has collided with " + collision.gameObject.name + " at position " + transform.position);
        //rb.velocity = Vector3.right * movementSpeed * movementAfterCollision;
        rb.velocity *= movementAfterCollision;
        //if (sphereSpawn != null)
        Instantiate(sphereSpawn, new Vector3(transform.position.x, transform.position.y + 12, transform.position.z), sphereSpawn.transform.rotation);
    }
}
