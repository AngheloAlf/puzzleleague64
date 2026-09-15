import sys
import os
from openai import OpenAI

GATEWAY_URL = "https://llm.merlinsoftware.es"
API_KEY = "sk-QLuTFQGk-35EAWG_jfl7OldrlEoLggu_QeQlf19y2_jM35wR"
MODEL = "gpt-5.6-sol"

client = OpenAI(
	base_url = GATEWAY_URL,
	api_key=API_KEY
)

def ask(prompt_file):
	with open(prompt_file, 'r') as f:
		content = f.read()

	response = client.chat.completions.create(
        	model=MODEL,
        	messages=[
            	{
                	"role": "system",
                	"content": "Eres un asistente experto en ingenieria inversa y decompilacion en C de Nintendo 64 (MIPS III, GCC 2.7.2 / IDO con -O2)."
            	},
            	{
                	"role": "user",
                	"content": content
            	}
        	],
        	temperature=0.1
    	)
	print(response.choices[0].message.content)

if __name__ == "__main__":
	if len(sys.argv) < 2:
		print("uso: uv run python tools/merlin_IA.py <archivo_prompt.txt>")
		sys.exit(1)
	ask(sys.argv[1])
