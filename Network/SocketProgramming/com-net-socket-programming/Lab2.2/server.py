import socket, json
from pyngrok import ngrok

def main():
    host = ""
    # TODO
    # Specify your local server port
    # =============================================
    port = 12345
    
    # =============================================
    is_running = True
    try:
        # Create a TCP socket
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            
            # TODO
            # Bind the socket to the host and port
            # =============================================
            s.bind((host, port))
            
            # =============================================
            s.settimeout(1.0)
            print(f"[INFO] Server started, listening on port {port}")
            
            # Expose the server using ngrok
            public_url = ngrok.connect(port, "tcp")
            print(f"[INFO] Server is accessible via public URL: {public_url}")
            
            while is_running:
                try:
                    # TODO
                    # Accept a connection from a client
                    # =============================================
                    s.listen(1)
                    client_socket, client_address = s.accept()
                    
                    # =============================================
                    print(f"[INFO] Connection accepted from {client_address}")
                    
                    with client_socket:
                        print(f"[INFO] Connected to: {client_address[0]}:{client_address[1]}")
                        
                        # TODO
                        # Receive a text message from the socket using a buffer size of 1024 bytes.
                        # The received message from the client should be "Hello World!"
                        # Ensure the response is decoded from UTF-8 format
                        # =============================================
                        data = client_socket.recv(1024).decode('utf-8')
                        
                        # =============================================
                        print("[INFO] Received message:", data)
                        
                        # TODO
                        # Respond "OK" to the client
                        # =============================================
                        client_socket.send("OK".encode('utf-8'))
                        
                        # =============================================
                        print(f"[INFO] Responded to Client {client_address[0]}:{client_address[1]}.")
                        print(f"[INFO] Client {client_address[0]}:{client_address[1]} disconnected.")
    
                except socket.timeout:
                    continue

    except KeyboardInterrupt:
        print("[INFO] Received shutdown signal (Ctrl+C). Stopping server...")
        is_running = False
    except Exception as e:
        print(f"[ERROR] Exception in server loop: {e}")
        
    print("[INFO] Server shutdown complete.")
            
if __name__ == '__main__':
    main()
