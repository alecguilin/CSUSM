using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;


public class PlayerMove : MonoBehaviour
{
    public float speed, jumpSpeed, rotateSpeed;
    public Text countText, winText, levelText, lifeText;
    public string nextLevel, mainMenu;
    private Scene m_scene;

    private Rigidbody rb;
    public LayerMask groundLayers;
    public CapsuleCollider col;
    private int vcCount, lifeCount;

    // Start is called before the first frame update
    void Start()
    {
        speed = 8;
        jumpSpeed = 6;
        rotateSpeed = 2.5f;

        vcCount = 0;
        lifeCount = 2;

        setCountText();

        winText.text = "";

        m_scene = SceneManager.GetActiveScene();
        levelText.text = m_scene.name;

        rb = GetComponent<Rigidbody>();
        col = GetComponent<CapsuleCollider>();
    }

    // Update is called once per frame
    void Update()
    {
        //player movement forwards and backwards and jump
        transform.Translate(0, 0, Input.GetAxis("Vertical") * Time.deltaTime * speed);
        //player rotation
        transform.Rotate(0, Input.GetAxis("Horizontal") * rotateSpeed, 0);
        if (IsGrounded() && Input.GetKeyDown(KeyCode.Space))
        {
            rb.AddForce(Vector3.up * jumpSpeed, ForceMode.Impulse);
        }

    }

    
    private bool IsGrounded()
    {
        return Physics.CheckCapsule(col.bounds.center, new Vector3(col.bounds.center.x, col.bounds.min.y, col.bounds.center.z), col.radius * .9f, groundLayers);
    }

    private void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Treasure")
        {
            Destroy(col.gameObject);
            vcCount++;
            setCountText();
        }
        else if (col.gameObject.tag == "Enemy")
        {
            Debug.Log("HIT)");
            Destroy(col.gameObject);
            lifeCount--;
            setCountText();
            if (lifeCount == 0)
            {
                SceneManager.LoadScene(mainMenu);
            }
        }
    }

    void setCountText()
    {
        countText.text = "VC Collected: " + vcCount.ToString() + "/2";
        lifeText.text = "Life Total: " + lifeCount.ToString() +"/2";
        if (vcCount >= 2)
        {
            winText.text = m_scene.name + " Complete!";
            //yield return new WaitForSeconds(2);
            SceneManager.LoadScene(nextLevel);

        }
    }
}

