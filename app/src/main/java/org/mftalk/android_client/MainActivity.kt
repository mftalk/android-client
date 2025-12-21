package org.mftalk.android_client

import android.os.Bundle
import android.text.Editable
import android.text.TextWatcher
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import org.mftalk.android_client.databinding.ActivityMainBinding


class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.sampleText.text = amberCencrypt("Welcome to MFTalk", "pizzalover122", 5374892, 991991948484874773)

        binding.sampleTextInput.addTextChangedListener(object : TextWatcher {
            override fun beforeTextChanged(s: CharSequence?, start: Int, count: Int, after: Int) {}
            override fun onTextChanged(s: CharSequence?, start: Int, before: Int, count: Int) {
                Log.d("demoViewDebug", binding.sampleTextInput.text.toString())
                binding.sampleText.text = amberCencrypt(binding.sampleTextInput.text.toString(), "pizzalover122", 5374892, 991991948484874773)
            }

            override fun afterTextChanged(s: Editable?) {}
        })
    }


    companion object {
        init {
            System.loadLibrary("android_client")
        }
        @JvmStatic
        external fun amberCencrypt(text: String, key: String, seed1: Long, seed2: Long): String
    }
}